//
// Created by kristapsn on 08.04.22.
//

#include "BMP.h"

std::ifstream BMP::openFile(const std::string &filename) {
    std::ifstream file{filename, std::ios::binary};
    std::string output;

    if (!file) {
        std::cout << "Err: cannot open " << filename << " file" << "\n\nQuitting...\n";
        exit(1);
    } else {
        return file;
    }
}

void BMP::readHeader() {
    image.read((char *) &bitmapfileheader.type, sizeof(bitmapfileheader.type));
    // convert big-endian to host endian
    bitmapfileheader.type = be16toh(bitmapfileheader.type);
    // check if file type is as expected to BMP standard
    if (bitmapfileheader.type != 16973) {
        std::cout << "This is not a correct BMP image!\n";
        exit(1);
    }

    image.read((char *) &bitmapfileheader.size, sizeof(bitmapfileheader.size));
    image.read((char *) &bitmapfileheader.reserved1, sizeof(bitmapfileheader.reserved1));
    image.read((char *) &bitmapfileheader.reserved2, sizeof(bitmapfileheader.reserved2));
    image.read((char *) &bitmapfileheader.offBits, sizeof(bitmapfileheader.offBits));


    // debug print
    std::cout << "Type: " << bitmapfileheader.type << "\n";
    std::cout << "Size: " << bitmapfileheader.size << "\n";
    std::cout << "Reserved 1: " << bitmapfileheader.reserved1 << "\n";
    std::cout << "Reserved 2: " << bitmapfileheader.reserved2 << "\n";
    std::cout << "Off Bits: " << bitmapfileheader.offBits << "\n";
}

void BMP::readInfoHeader() {
    image.read((char *) &bitmapinfoheader.size, sizeof(bitmapinfoheader.size));
    image.read((char *) &bitmapinfoheader.width, sizeof(bitmapinfoheader.width));
    image.read((char *) &bitmapinfoheader.height, sizeof(bitmapinfoheader.height));
    image.read((char *) &bitmapinfoheader.planes, sizeof(bitmapinfoheader.planes));
    image.read((char *) &bitmapinfoheader.bitCount, sizeof(bitmapinfoheader.bitCount));
    image.read((char *) &bitmapinfoheader.bitCompression, sizeof(bitmapinfoheader.bitCompression));
    image.read((char *) &bitmapinfoheader.sizeImage, sizeof(bitmapinfoheader.sizeImage));
    image.read((char *) &bitmapinfoheader.xPixelsPerMeter, sizeof(bitmapinfoheader.xPixelsPerMeter));
    image.read((char *) &bitmapinfoheader.yPixelsPerMeter, sizeof(bitmapinfoheader.yPixelsPerMeter));
    image.read((char *) &bitmapinfoheader.colorsUsed, sizeof(bitmapinfoheader.colorsUsed));
    image.read((char *) &bitmapinfoheader.colorsImportant, sizeof(bitmapinfoheader.colorsImportant));

    std::cout << "w: " << bitmapinfoheader.width << "\n";
    std::cout << "h: " << bitmapinfoheader.height << "\n";  
}
