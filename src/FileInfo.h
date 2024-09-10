#pragma once
#include <string>
#include <filesystem>
#include <shlobj.h>

struct FileInfo
{
	const std::filesystem::path exPath, currentPath, directoryPath;

	FileInfo(const std::filesystem::path _exPath, const std::filesystem::path _currentPath, const std::filesystem::path _directoryPath);
	
	
};

