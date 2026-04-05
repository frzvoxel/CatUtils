#include <iostream>
#include <ostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::string argu = argv[1];

        std::string line;

        std::ifstream file(argu);

        if (file.is_open()) {

            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Error file" << std::endl;
        }
    }
}
