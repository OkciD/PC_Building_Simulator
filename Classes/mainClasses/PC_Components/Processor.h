//
// Created by evgenia on 24.05.17.
//

#ifndef MYGAME_PROCESSOR_H
#define MYGAME_PROCESSOR_H

#include "../Detail.h"

class Processor : public Detail
{
public:
    Processor() {}

    ~Processor() {}

    std::string GetSocketType();

private:
    std::string socketType;
};


#endif //MYGAME_PROCESSOR_H
