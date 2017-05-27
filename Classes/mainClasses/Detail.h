//
// Created by evgenia on 24.05.17.
//

#ifndef MYGAME_DETAIL_H
#define MYGAME_DETAIL_H


//#include <iostream>
#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

class Detail
{
public:
    Detail(ComponentTypes type, std::string resComponentImage);

    ~Detail() {}

    std::string GetComponentImage() { return resComponentImage; };

    int GetRating();

    unsigned int GetPrice();

    ComponentTypes GetType() { return type; };

    Vec2 GetSize() { return size; };

    Vec2 GetPosition() { return position; };


private:
    ComponentTypes type;

    std::string resComponentImage;

    int performanceRating;

    unsigned int price;

    Vec2 size;

    Vec2 position;
};


#endif //MYGAME_DETAIL_H
