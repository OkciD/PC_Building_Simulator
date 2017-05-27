//
// Created by evgenia on 24.05.17.
//

#ifndef MYGAME_STORAGEDEVICE_H
#define MYGAME_STORAGEDEVICE_H

#include "../Detail.h"

class StorageDevice : public Detail
{
public:
//    StorageDevice {}

    ~StorageDevice() {}

    std::string GetType(); //??
private:

    std::string Type;
};


#endif //MYGAME_STORAGEDEVICE_H
