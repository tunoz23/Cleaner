#include "FileCleaner.h"


extern std::string SelectFolder();

int main()
{   

    std::string path = SelectFolder();
    FileCleaner::putInFolders(path);
    int i;
    std::cout << "Type 1 and press Enter if you want to retrieve your files back: ";
    std::cin >> i;
    if (i == 1)
        FileCleaner::retrieveFromFolders();
    std::cout << "They successfully retrieved back.";
    
    std::cin.get();
    

}