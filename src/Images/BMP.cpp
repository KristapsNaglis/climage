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

void BMP::getFileSize() {
    unsigned int headerSizeBytes = 14;
    std::vector<unsigned char> header(headerSizeBytes);
    image.read((char *) &header[0], headerSizeBytes);

//    for (auto h: header) {
//        std::cout << "0x" << std::hex << (int) h << "\n";
//    }

    std::stringstream ss;
    for (int i = 6; i > 1; --i) {
        ss << std::hex << (int) header[i];
    }

    std::cout << "Hex: 0x" << ss.str() << "\n";
    unsigned int x;
    ss >> x;
    std::cout << "Int: " << x << " bytes\n";
}