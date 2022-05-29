//
// Created by kristapsn on 08.04.22.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <endian.h>

#ifndef CLIMAGE_BMP_H
#define CLIMAGE_BMP_H

// DOC: https://docs.microsoft.com/en-us/windows/win32/gdi/bitmap-storage?redirectedfrom=MSDN
class BMP {

private:
    std::ifstream image;

    struct BITMAPFILEHEADER { // general info about file
        uint16_t type{}; // always must be str "BM" / hex 0x424d / int 16973
        uint32_t size{}; // size of image in bytes
        uint16_t reserved1{}; // must be 0
        uint16_t reserved2{}; // must be 0
        uint32_t offBits{}; // offset, in bytes, from the beginning of the BITMAPFILEHEADER structure to the bitmap bits
    };

    struct BITMAPINFOHEADER { // info about dimensions and color format
        uint32_t size{};
        uint32_t width{};
        uint32_t height{};
        uint16_t planes{};
        uint16_t bitCount{};
        uint32_t bitCompression{};
        uint32_t sizeImage{};
        uint32_t xPixelsPerMeter{};
        uint32_t yPixelsPerMeter{};
        uint32_t colorsUsed{};
        uint32_t colorsImportant{};
    };

    BITMAPFILEHEADER bitmapfileheader;
    BITMAPINFOHEADER bitmapinfoheader;

    std::ifstream openFile(const std::string &filename);

    void readHeader();
    void readInfoHeader();

public:
    BMP(const std::string &filename) {
        image = openFile(filename);
        readHeader();
        readInfoHeader();
    }

};


#endif //CLIMAGE_BMP_H
