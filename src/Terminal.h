//
// Created by kristapsn on 05.04.22.
//
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>


#ifndef CLIMAGE_TERMINAL_H
#define CLIMAGE_TERMINAL_H


class Terminal {
private:
    unsigned int xSize{};
    unsigned int ySize{};

public:
    void setSize();

    std::pair<unsigned int, unsigned int> getSize();
};


#endif //CLIMAGE_TERMINAL_H
