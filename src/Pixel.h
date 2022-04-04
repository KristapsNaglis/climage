//
// Created by kristapsn on 02.04.22.
//
#include <vector>
#include <string>
#include <iostream>

#ifndef CLIMAGE_PIXEL_H
#define CLIMAGE_PIXEL_H


class Pixel {
private:
//    std::vector<unsigned int> color;
    unsigned int r{};
    unsigned int g{};
    unsigned int b{};

public:
    Pixel(unsigned int r, unsigned int g, unsigned int b) {
        setColors(r, g, b);
    }

    void setColors(unsigned int r, unsigned int g, unsigned b);

    std::vector<unsigned int> getColors();

    [[nodiscard]] std::string getColors24bit() const;

    unsigned int getRed();

};


#endif //CLIMAGE_PIXEL_H
