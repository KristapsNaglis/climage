//
// Created by kristapsn on 02.04.22.
//

#include "Pixel.h"

void Pixel::setColors(unsigned int red, unsigned int green, unsigned int blue) {
    r = red;
    g = green;
    b = blue;
}

std::vector<unsigned int> Pixel::getColors() {
    return std::vector<unsigned int>{r, g, b};
}

std::string Pixel::getColors24bit() const {
    return std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b);
}

unsigned int Pixel::getRed() {
    return r;
}


//std::ostream &operator<<(std::ostream &os, const Pixel &pixel) {
//    std::vector<unsigned int> pixels = getColors()
//
//    os << pixel.color[0] << pixel.color[1] << pixel.color[2];
//    return os;pixels[x][y].getColors24bit()
//}
