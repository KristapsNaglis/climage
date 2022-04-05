//
// Created by kristapsn on 02.04.22.
//

#include <iostream>
#include <sstream>
#include "Image.h"
#include "Pixel.h"
#include "Terminal.h"


int main(int argc, char **argv) {
    // Set terminal window size
    Terminal terminal;
    terminal.setSize();

    auto termSize = terminal.getSize();

    std::cout << "term size => x: " << termSize.first << " y: " << termSize.second << "\n";

    if (argc != 3) {
        std::cout << "Must have two parameters - x, y\n";
        return 1;
    }

    // Need to improve conversion from argv string to uint
    std::istringstream issX(argv[1]);
    unsigned int x;
    issX >> x;

    std::istringstream issY(argv[2]);
    unsigned int y;
    issY >> y;


    std::cout << "Args: " << x << ", " << y << "\n";


    Image image(termSize.first, termSize.second - 1);

    std::pair<unsigned int, unsigned int> imageSize = image.getSize();
    std::cout << "Image size => x: " << imageSize.first << " y: " << imageSize.second << "\n";

//    image.drawRectangle();

    image.createImage();

    image.drawImage();

    std::cout << "Press ENTER to quit...";
    std::string t;
    if (std::getline(std::cin, t)) {
        return 0;
    }
}