#include <iostream>
#include <filesystem>



namespace fs = std::filesystem;

void GetFile(char* argv);

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "Usage D [Path]\n"; 
    } else if (argc >= 2) {
        GetFile(argv[1]);
    }

    return 0;
}

void GetFile(char* argv) {
    fs::path path = argv;

    try {
        fs::remove(path);
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error" << e.what() << "\n";
    }
}


