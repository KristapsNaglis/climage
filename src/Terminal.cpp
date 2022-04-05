//
// Created by kristapsn on 05.04.22.
//

#include "Terminal.h"

void Terminal::setSize() {
    struct winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    xSize = w.ws_col;
    ySize = w.ws_row;
}

std::pair<unsigned int, unsigned int> Terminal::getSize() {
    return std::pair<unsigned int, unsigned int>({xSize, ySize});
}
