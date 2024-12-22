#ifndef TEXTFILEREADER_H
#define TEXTFILEREADER_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include <string>

class TextFileReader {
private:
    char* filename;
public:
    TextFileReader();
    TextFileReader(const char* filename);
    TextFileReader(const TextFileReader& other);
    ~TextFileReader();

    void setFilename(const char* filename);
    const char* getFilename() const;

    void filter();
};

#endif // TEXTFILEREADER_H
