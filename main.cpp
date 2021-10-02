#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath;
    std::cout << "Input your file path: ";
    std::cin >> filePath;
    std::ifstream file;
    file.open(filePath);

    while (!file.is_open()) {
        std::cout << "Something goes wrong. Try again ('1' for exit): ";
        std::cin >> filePath;
        if (filePath == "1") return 1;
        file.open(filePath);
    }
    
    std::string str;

    while (!file.eof()){
        std::getline(file, str);
        std::cout << str << std::endl;
    }
    file.close();
    return 0;
}
