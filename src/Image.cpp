//
// Created by kristapsn on 02.04.22.
//

#include "Image.h"

void Image::setSize(const unsigned int &x, const unsigned int &y) {
    xSize = x;
    ySize = y;
}

std::pair<unsigned int, unsigned int> Image::getSize() {
    return {xSize, ySize};
}

void Image::drawRectangle() const {
    std::vector<unsigned int> rgb{0, 0, 0};
    unsigned int step = 255 / ((xSize / 2) * ySize);

    unsigned int counter = 0;
    for (int x = 0; x < xSize / 2; ++x) {
        for (int y = 0; y < ySize; ++y) {
            std::cout << "\033[48;2;"
                      << rgb[0] + step * counter << ";"
                      << rgb[1] << ";"
                      << rgb[2] << "m \033[0m";
            counter++;
        }
        counter++;
        std::cout << "\n";
    }
}

void Image::createImage() {
    // Create pixels
    for (int x = 0; x < xSize / 2; ++x) {
        std::vector<Pixel> row;
        for (int y = 0; y < ySize; ++y) {
            Pixel pixel(255-y*10, 155-x*10, 0);
            row.push_back(pixel);
        }
        pixels.push_back(row);
    }
}

void Image::drawImage() {
    for (int x = 0; x < xSize / 2; ++x) {
        for (int y = 0; y < ySize; ++y) {
            std::cout << "\033[48;2;" << pixels[x][y].getColors24bit() << "m \033[0m";
        }
        std::cout << "\n";
    }
}