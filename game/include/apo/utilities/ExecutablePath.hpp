
#pragma once

#include <filesystem>
#include <stdexcept>
#include <string>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <unistd.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#endif

namespace apo {

inline std::filesystem::path executable_path() {
#if defined(_WIN32)

	std::wstring buffer(MAX_PATH, L'\0');
	DWORD size = GetModuleFileNameW(nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));

	if (size == 0) throw std::runtime_error("GetModuleFileNameW failed");

	buffer.resize(size);
	return std::filesystem::path(buffer);

#elif defined(__linux__)

	std::string buffer(1024, '\0');
	ssize_t size = readlink("/proc/self/exe", buffer.data(), buffer.size());

	if (size == -1) throw std::runtime_error("readlink failed");

	return std::filesystem::path(std::string(buffer.data(), size));

#elif defined(__APPLE__)

	uint32_t size = 0;
	_NSGetExecutablePath(nullptr, &size); // get required size

	std::string buffer(size, '\0');
	if (_NSGetExecutablePath(buffer.data(), &size) != 0) throw std::runtime_error("_NSGetExecutablePath failed");

	return std::filesystem::path(buffer);

#else
#error Unsupported platform
#endif
}

inline std::filesystem::path executable_path_canonical() { return std::filesystem::canonical(executable_path()); }

inline std::filesystem::path executable_dir() { return executable_path().parent_path(); }

inline std::filesystem::path executable_dir_canonical() { return executable_path_canonical().parent_path(); }

} // namespace apo
