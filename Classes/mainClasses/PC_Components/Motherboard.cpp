//
// Created by evgenia on 24.05.17.
//

#include "Motherboard.h"

std::string Motherboard::GetFormFactor()
{
    return formFactor;
}

std::string Motherboard::GetMemoryFormFactor()
{
    return memoryFormFactor;
}

std::string Motherboard::GetMemoryType()
{
    return memoryType;
}

std::string Motherboard::GetPortType()
{
    return portType;
}

std::string Motherboard::GetProcessorSocket()
{
    return processorSocket;
}