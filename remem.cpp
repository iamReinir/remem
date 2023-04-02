#include <iostream>
#include <fstream>
#include "Arguments.h"
#include "remem_constants.h"

void pause()
{
    std::cout << "Press any key to quit...";
    std::cin.get();
}

void show_error(const char* error_msg = "")
{
    std::cout << error_msg << "\n";
}

void exit_with_error(const char* error_msg = "")
{
    show_error(error_msg);
    getchar();
    exit(0);
}


void show_help()
{
    std::ifstream helpfile(remem_constants::helpFile);
    if (!helpfile.is_open())
    {
        exit_with_error("Can't open help file");
    }
    std::string x;
    while (helpfile.good())
    {        
        std::getline(helpfile, x);
        std::cout << x << "\n";
    }    
}

int main(int argc, char* argv[])
{   
    using namespace Arguments;
    Type choice = type_of(argc, argv);
    switch (choice)
    {
    case Type::add_diary:
    case Type::setting:        
    default:
        show_error("Unsupported choice");
        show_help();
        break;
    }
    open_config_file();
    pause();
}


