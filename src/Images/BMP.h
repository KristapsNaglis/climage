//
// Created by kristapsn on 08.04.22.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

#ifndef CLIMAGE_BMP_H
#define CLIMAGE_BMP_H

// DOC: https://docs.microsoft.com/en-us/windows/win32/gdi/bitmap-storage?redirectedfrom=MSDN
class BMP {

private:
    std::ifstream image;

    struct BITMAPFILEHEADER {
        std::string type;
        unsigned int size;
        std::string reserved1;
        std::string reserved2;
        unsigned int offBits;
    };

    std::ifstream openFile(const std::string &filename);


public:
    BMP(const std::string &filename) {
        image = openFile(filename);
    }
    void getFileSize();

};


#endif //CLIMAGE_BMP_H
