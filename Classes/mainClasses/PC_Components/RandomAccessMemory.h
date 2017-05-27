//
// Created by evgenia on 24.05.17.
//

#ifndef MYGAME_MEMORY_H
#define MYGAME_MEMORY_H

#include "../Detail.h"
#include <string>

class RandomAccessMemory : public Detail
{
private:
    std::string type;

public:
//    RandomAccessMemory() {}

    ~RandomAccessMemory() {}

    std::string getType();
};


#endif //MYGAME_MEMORY_H
