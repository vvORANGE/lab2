#include "TextFileReader.h"

TextFileReader::TextFileReader() : filename(nullptr) {
    std::cout << "Default constructor called." << std::endl;
}

TextFileReader::TextFileReader(const char* filename) {
    std::cout << "Parameterized constructor called." << std::endl;
    setFilename(filename);
}

TextFileReader::TextFileReader(const TextFileReader& other) {
    std::cout << "Copy constructor called." << std::endl;
    if (other.filename) {
        setFilename(other.filename);
    } else {
        filename = nullptr;
    }
}

TextFileReader::~TextFileReader() {
    std::cout << "Destructor called." << std::endl;
    delete[] filename;
}

void TextFileReader::setFilename(const char* filename) {
    delete[] this->filename;
    this->filename = new char[strlen(filename) + 1];
    strcpy(this->filename, filename);
}

const char* TextFileReader::getFilename() const {
    return filename;
}

void TextFileReader::filter() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open the file.");
    }

    std::cout << "Words starting with vowels:" << std::endl;
    std::string word;
    while (file >> word) {
        if (!word.empty() && 
            (word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || 
             word[0] == 'O' || word[0] == 'U' || 
             word[0] == 'a' || word[0] == 'e' || 
             word[0] == 'i' || word[0] == 'o' || 
             word[0] == 'u')) {
            std::cout << word << std::endl;
        }
    }

    file.close();
}
