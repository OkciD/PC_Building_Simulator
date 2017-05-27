//
// Created by sergey on 27.05.17.
//

#ifndef MYGAME_VALIDATOR_H
#define MYGAME_VALIDATOR_H


#include <cocos2d.h>
#include "MiniComponentImage.h"

#include "Computer.h"
#include <vector>

USING_NS_CC;


class Validator
{
public:
    Validator() {}

    ~Validator() {}

    bool Validate(cocos2d::Vec2 p, MiniComponentImage *miniImage, ComponentImage *detailImage);

private:

    bool validateCase(cocos2d::Vec2 p, MiniComponentImage *miniImage, ComponentImage *detailImage);

//    void validateMotherboard(cocos2d::Vec2 p, MiniComponentImage *miniImage);

    void error(MiniComponentImage *miniImage);

    bool isMotherboard = false;

    Computer computer;
};


#endif //MYGAME_VALIDATOR_H
