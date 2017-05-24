//
// Created by evgenia on 24.05.17.
//

#include "Computer.h"


bool Computer::AddRandomAccessMemory1(RandomAccessMemory *randomAccessMemory)
{
    if (this->randomAccessMemory1 == nullptr)
    {
        this->randomAccessMemory1 = randomAccessMemory;
        return true;
    }
    return false;
}

bool Computer::AddRandomAccessMemory2(RandomAccessMemory *randomAccessMemory)
{
    if (this->randomAccessMemory2 == nullptr)
    {
        this->randomAccessMemory2 = randomAccessMemory;
        return true;
    }
    return false;
}

bool Computer::AddRandomAccessMemory3(RandomAccessMemory *randomAccessMemory)
{
    if (this->randomAccessMemory3 == nullptr)
    {
        this->randomAccessMemory3 = randomAccessMemory;
        return true;
    }
    return false;
}

bool Computer::AddRandomAccessMemory4(RandomAccessMemory *randomAccessMemory)
{
    if (this->randomAccessMemory4 == nullptr)
    {
        this->randomAccessMemory4 = randomAccessMemory;
        return true;
    }
    return false;
}

bool Computer::AddCoolingDevice(CoolingDevice *coolingDevice)
{
    if (this->coolingDevice == nullptr)
    {
        this->coolingDevice = coolingDevice;
        return true;
    }
    return false;
}

bool Computer::AddMotherboard(Motherboard *motherboard)
{
    if (this->motherboard == nullptr)
    {
        this->motherboard = motherboard;
        return true;
    }
    return false;
}

bool Computer::AddProcessor(Processor *processor)
{
    if (this->processor == nullptr)
    {
        this->processor = processor;
        return true;
    }
    return false;
}

bool Computer::AddStorageDevice(StorageDevice *storageDevice)
{
    if (this->storageDevice == nullptr)
    {
        this->storageDevice = storageDevice;
        return true;
    }
    return false;
}

bool Computer::AddVideocard(Videocard *videocard)
{
    if (this->videocard == nullptr)
    {
        this->videocard = videocard;
        return true;
    }
    return false;
}


RandomAccessMemory *Computer::DropRandomAccessMemory1()
{
    RandomAccessMemory *droppedRandomAccessMemory = randomAccessMemory1;
    randomAccessMemory1 = nullptr;
    return droppedRandomAccessMemory;
}

RandomAccessMemory *Computer::DropRandomAccessMemory2()
{
    RandomAccessMemory *droppedRandomAccessMemory = randomAccessMemory2;
    randomAccessMemory2 = nullptr;
    return droppedRandomAccessMemory;
}

RandomAccessMemory *Computer::DropRandomAccessMemory3()
{
    RandomAccessMemory *droppedRandomAccessMemory = randomAccessMemory3;
    randomAccessMemory3 = nullptr;
    return droppedRandomAccessMemory;
}

RandomAccessMemory *Computer::DropRandomAccessMemory4()
{
    RandomAccessMemory *droppedRandomAccessMemory = randomAccessMemory4;
    randomAccessMemory4 = nullptr;
    return droppedRandomAccessMemory;
}

CoolingDevice *Computer::DropCoolingDevice()
{
    CoolingDevice *droppedCoolingDevice = coolingDevice;
    coolingDevice = nullptr;
    return droppedCoolingDevice;
}

Motherboard *Computer::DropMotherboard()
{
    Motherboard *droppedMotherboard = motherboard;
    motherboard = nullptr;
    return droppedMotherboard;
}

Processor *Computer::DropProcessor()
{
    Processor *dropedProcessor = processor;
    processor = nullptr;
    return dropedProcessor;
}

StorageDevice *Computer::DropStorageDevice()
{
    StorageDevice *droppedStorageDevice = storageDevice;
    storageDevice = nullptr;
    return droppedStorageDevice;
}

Videocard *Computer::DropVideocard()
{
    Videocard *dropedVideocard = videocard;
    videocard = nullptr;
    return dropedVideocard;
}

int Computer::EstimatePerformance()
{
    unsigned int resultPrice;
    int resultRating;//sum
    return 0;
}

bool Computer::CheckAvailabilityOfComponents()
{
    if (!storageDevice || !motherboard || !processor || !videocard || !coolingDevice ||
        !(randomAccessMemory1 || randomAccessMemory2 || randomAccessMemory3 || randomAccessMemory4))
    {
        return false;
    }
    return true;

}