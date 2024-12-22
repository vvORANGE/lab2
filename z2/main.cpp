#include "TextFileReader.h"

int main() {
    try {
        char filename[256];
        std::cout << "Enter the filename: ";
        std::cin >> filename;

        TextFileReader textFileReader(filename);
        textFileReader.filter();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
