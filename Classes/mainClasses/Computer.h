//
// Created by evgenia on 24.05.17.
//

#ifndef MYGAME_COMPUTER_H
#define MYGAME_COMPUTER_H

#include "PC_Components/RandomAccessMemory.h"
#include "PC_Components/CoolingDevice.h"
#include "PC_Components/Motherboard.h"
#include "PC_Components/Processor.h"
#include "PC_Components/StorageDevice.h"
#include "PC_Components/Videocard.h"


class Computer
{
public:
    Computer() {}

    ~Computer() {}

    int EstimatePerformance();

    bool CheckAvailabilityOfComponents();


    bool AddRandomAccessMemory1(RandomAccessMemory *randomAccessMemory);

    bool AddRandomAccessMemory2(RandomAccessMemory *randomAccessMemory);

    bool AddRandomAccessMemory3(RandomAccessMemory *randomAccessMemory);

    bool AddRandomAccessMemory4(RandomAccessMemory *randomAccessMemory);

    bool AddCoolingDevice(CoolingDevice *coolingDevice);

    bool AddMotherboard(Motherboard *motherboard);

    bool AddProcessor(Processor *processor);

    bool AddStorageDevice(StorageDevice *storageDevice);

    bool AddVideocard(Videocard *videocard);


    RandomAccessMemory *DropRandomAccessMemory1();

    RandomAccessMemory *DropRandomAccessMemory2();

    RandomAccessMemory *DropRandomAccessMemory3();

    RandomAccessMemory *DropRandomAccessMemory4();

    CoolingDevice *DropCoolingDevice();

    Motherboard *DropMotherboard();

    Processor *DropProcessor();

    StorageDevice *DropStorageDevice();

    Videocard *DropVideocard();

private:
    RandomAccessMemory *randomAccessMemory1 = nullptr;
    RandomAccessMemory *randomAccessMemory2 = nullptr;
    RandomAccessMemory *randomAccessMemory3 = nullptr;
    RandomAccessMemory *randomAccessMemory4 = nullptr;
    CoolingDevice *coolingDevice = nullptr;
    Motherboard *motherboard = nullptr;
    Processor *processor = nullptr;
    StorageDevice *storageDevice = nullptr;
    Videocard *videocard = nullptr;
};


#endif //MYGAME_COMPUTER_H
