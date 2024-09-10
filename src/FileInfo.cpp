#include "FileInfo.h"

FileInfo::FileInfo(const std::filesystem::path _exPath,const std::filesystem::path _currentPath,const std::filesystem::path _directoryPath)
	: exPath(_exPath), currentPath(_currentPath), directoryPath(_directoryPath){}
