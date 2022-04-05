//
// Created by kristapsn on 02.04.22.
//
#include <utility>
#include <iostream>
#include <vector>
#include "Pixel.h"

#ifndef CLIMAGE_IMAGE_H
#define CLIMAGE_IMAGE_H


class TermImage {
private:
    unsigned int xSize{}, ySize{};
    std::vector<std::vector<Pixel>> pixels = {};

public:
    TermImage(const unsigned int x, const unsigned int y){
        setSize(x, y);
    }

    void setSize(const unsigned int &xSize, const unsigned int &ySize);

    std::pair<unsigned int, unsigned int> getSize();

    void drawRectangle() const;

    void createImage();

    void drawImage();

};


#endif //CLIMAGE_IMAGE_H
