#ifndef NAVIGATION_H
#define NAVIGATION_H
namespace fs = std::filesystem;

void changePWD();
void changePWD_upward();
void display_directory_contents();
void switch_logic(); 
void display_current_path();
void copy_directory_contents(const fs::path& source, const fs::path& destination);
void copy_directory_helper(); 
#endif // NAVIGATION_H