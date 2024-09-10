#include "FileCleaner.h"


std::vector<FileInfo> FileCleaner::files = std::vector<FileInfo>();
bool FileCleaner::putInFolders(std::string path)
{
    Timer timer;
    if (path.empty()) return 1;

    std::cout << path << "\n";

    std::vector<fs::directory_entry> vec;
    for (const auto& entry : fs::directory_iterator(path))
    {
        vec.push_back(entry);
        std::cout << entry.path() << std::endl;

    }

    for (const auto& file : vec)
    {

        auto fsPath = static_cast<fs::path>(file).filename();

        const std::string directoryPath = path + "\\" + fsPath.extension().string();
        const std::string newPath = path + "\\" + fsPath.extension().string() + "\\" + fsPath.filename().string();
        fs::create_directory(directoryPath);

        FileInfo _file(file.path(), newPath, directoryPath);
        FileCleaner::files.push_back(_file);
        fs::rename(file.path(), newPath);


    }
}


void FileCleaner::retrieveFromFolders() 
{

    for (const auto& file : FileCleaner::files)
    {
        fs::rename(file.currentPath, file.exPath);
        fs::path dirPath = file.directoryPath.string() + "\\";

        if (fs::is_empty(dirPath))
            fs::remove(file.directoryPath);
    }


}


int CALLBACK BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData) {
    switch (uMsg) {
    case BFFM_INITIALIZED:
        SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM)lpData);
        break;
    }
    return 0;
}

std::string SelectFolder() {
    BROWSEINFO bi = { 0 };
    bi.lpszTitle = L"Select a folder that you want to clean up:";
    bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
    bi.lpfn = BrowseCallbackProc;
    bi.lParam = (LPARAM)"C:/";

    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
    if (pidl != NULL)
    {
        std::string path(MAX_PATH, '\0');
        if (SHGetPathFromIDListA(pidl, &path[0]))
        {
            path.resize(strlen(path.c_str()));
            return path;
        }
        CoTaskMemFree(pidl);  // Free the returned ITEMIDLIST
    }
    return std::string();
}
