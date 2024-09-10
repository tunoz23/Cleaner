#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <filesystem>
#include <Windows.h>
#include <shlobj.h>
#include "FileInfo.h"
#include "utils.h"



class FileCleaner
{
private: 
    static std::vector<FileInfo> files;

  
public:
    FileCleaner() = delete;

    static bool  putInFolders(std::string path);
    
    static void retrieveFromFolders();
    
};

