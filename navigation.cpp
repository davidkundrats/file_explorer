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
//copy contents of one directory to another
void copy_directory_contents(const fs::path& source, const fs::path& destination);


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
void copy_directory_contents(const fs::path& source, const fs::path& destination) {
    std::string destination_str = destination.string();

     if(!destination.empty() && destination_str[0] == '~'){ 
        const char* home_dir = std::getenv("HOME");
        if(home_dir != nullptr)
            destination_str.replace(0, 1, home_dir);
        else
            std::cout << "Home directory not found." << std::endl;
    }
    if (!fs::exists(source) || !fs::is_directory(source)) {
        std::cout << "Source directory does not exist or is not a directory." << std::endl;
        return;
    }

    if (!fs::exists(destination_str) || !fs::is_directory(destination_str)) {
        std::cout << "Destination directory does not exist or is not a directory." << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(source)) {
        const fs::path entry_path = entry.path();
        const fs::path destination_path = destination_str / entry_path.filename();

        try {
            if (fs::is_directory(entry_path)) {
                fs::copy(entry_path, destination_path, fs::copy_options::recursive);
            } else {
                fs::copy(entry_path, destination_path);
            }
        } catch (const std::exception& e) {
            std::cerr << "Error copying " << entry_path << ": " << e.what() << std::endl;
        }
    }

    std::cout << "Contents of " << source << " copied to " << destination_str << std::endl;
}
void copy_directory_helper(){ 
     std::cout << "Enter destination directory" << '\n';
                std::string destination;
                std::cin >> destination;
                fs::path source = fs::current_path();
                std::cout << "Destination: " << destination << '\n'; 
                std::cout << "Source: " << source << std::endl;
                copy_directory_contents(source, destination);
}
