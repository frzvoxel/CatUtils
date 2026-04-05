#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs =  std::filesystem;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "Usage: qe [path] [file_name] OR qe [file_name]\n";
    } 
    else if (argc == 2) {
        std::ofstream file(argv[1]);
        if (file.is_open()) file.close();
    } 
    else if (argc >= 3) {
        fs::path dir = argv[1];
        fs::path file_name = argv[2];
        fs::path full_path = dir / file_name; 
        
        fs::create_directories(dir); 

        std::ofstream file(full_path);
        if (file.is_open()) file.close();
    }
}

