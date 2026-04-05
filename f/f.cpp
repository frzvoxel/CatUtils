#include <iostream>
#include <filesystem>
#include <ostream>
#include <string>

namespace fs = std::filesystem;

fs::path GetCurrentFolder();

void ListFile();

int main() {
    ListFile();
}

fs::path GetCurrentFolder() {
    fs::path CurrentFolder = fs::current_path();

    return CurrentFolder;
}


void ListFile() {
    fs::path path = GetCurrentFolder();

    try {
        if (fs::exists(path) && fs::is_directory(path)) {
            for (const auto& entry : fs::directory_iterator(path)) {
                std::cout << entry.path().filename() << std::endl;
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error" << e.what() << std::endl;
    }
}
