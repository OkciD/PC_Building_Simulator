//
// Created by evgenia on 24.05.17.
//

#ifndef MYGAME_MOTHERBOARD_H
#define MYGAME_MOTHERBOARD_H

#include "../Detail.h"

class Motherboard : public Detail
{
public:
    Motherboard() {}

    ~Motherboard() {}

    std::string GetFormFactor();

    std::string GetProcessorSocket();

    std::string GetMemoryType();

    std::string GetMemoryFormFactor();

    std::string GetPortType();

private:
    std::string formFactor;
    std::string processorSocket;
    std::string memoryType;
    std::string memoryFormFactor;
    std::string portType;
};


#endif //MYGAME_MOTHERBOARD_H
