#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath;
    std::cout << "Input your file path: ";
    std::cin >> filePath;
    std::ifstream file;
    file.open(filePath, std::ios::binary);

    while (!file.is_open()) {
        std::cout << "Something goes wrong. Try again ('1' for exit): ";
        std::cin >> filePath;
        if (filePath == "1") return 1;
        file.open(filePath);
    }
    
    char buffer[20];
    while (file.read(buffer, sizeof(buffer) - 1), file.gcount() != 0){
        buffer[file.gcount()] = 0;
        std::cout << buffer;
    }
    file.close();
    return 0;
}
