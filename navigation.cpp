#include <filesystem> 
#include <iostream>
namespace fs = std::filesystem;

//change current path downward
void changePWD();
//change current path upward
void changePWD_upward();
//display current directory contents
void display_directory_contents();
//gives full path of current directory
void display_current_path(); 


void display_current_path(){ 
fs::path current_path = fs::current_path();
std::cout << "Current path is: " << current_path << std::endl;
}

void changePWD_upward()
{ 
fs::path current_path = fs::current_path();
current_path = current_path.parent_path();
fs::current_path(current_path);
}

void changePWD() 
{ 
    std::string new_directory; 
    std::cout << "Enter new directory: " << '\n';
    std::getline(std::cin, new_directory);
    std::cin >> new_directory;
    fs::path current_path = fs::current_path();
    
    if(!new_directory.empty() && new_directory[0] == '~'){ 
        const char* home_dir = std::getenv("HOME");
        if(home_dir != nullptr)
            new_directory.replace(0, 1, home_dir);
        else
            std::cout << "Home directory not found." << std::endl;
    }
   
    if(fs::exists(new_directory) && fs::is_directory(new_directory))
    {
        current_path /= new_directory;
        fs::current_path(current_path);
    }
    else
        std::cout << "Directory does not exist." << std::endl;
}
void display_directory_contents(){ 
    fs::path current_path = fs::current_path();
    for(const auto& entry: fs::directory_iterator(current_path))
    std::cout << entry.path() << std::endl;
}

