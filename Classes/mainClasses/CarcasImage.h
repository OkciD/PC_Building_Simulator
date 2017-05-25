//
// Created by sergey on 25.05.17.
//

#ifndef MYGAME_CARCASIMAGE_H
#define MYGAME_CARCASIMAGE_H

#include "CustomSprite.h"
#include "DetailImage.h"

USING_NS_CC;

class CarcasImage :  public CustomSprite
{
public:
    static CarcasImage *create(const char *resCarcasImage);
};


#endif //MYGAME_CARCASIMAGE_H
