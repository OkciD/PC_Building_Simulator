//
// Created by sergey on 20.05.17.
//

#ifndef MYGAME_DETAILIMAGE_H
#define MYGAME_DETAILIMAGE_H


#include "CustomSprite.h"
#include "ListHeaderItem.h"
#include "MainScene.h"
#include "Detail.h"
#include "../mainClasses/PC_Components/Motherboard.h"

USING_NS_CC;

class DetailImage : public CustomSprite
{
public:
//
    DetailImage() {}

    DetailImage(std::string Detail) { detail = Detail; }

    ~DetailImage() {};

    static DetailImage *create(const char *resDetailImage);

    std::string detail;

    struct DetailMargin
    {
        double x;
        double y;
        double lenghtX;
        double lenghtY;

        DetailMargin(double X, double Y, double LenghtX, double LenghtY)
        {
            x = X;
            y = Y;
            lenghtX = LenghtX;
            lenghtY = LenghtY;
        }
    };

    float GetWithToHeightRatio() { return withToHeightRatio; };

private:
    void initOptions();

    void addEvents();

    void touchCancelledEvent(cocos2d::Touch *touch, cocos2d::Event *_p);

    void moveEvent(cocos2d::Touch *touch, cocos2d::Event *_p);

    bool onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *_p);
//
//    void paintMotherboard(cocos2d::Vec2 p);
//
//    void paintStorageDevice(cocos2d::Vec2 p);
//
//    void paintPowerSupply(cocos2d::Vec2 p);

    float withToHeightRatio = 0;

    Vec2 mTouchMovePosition;

    Vec2 mPreviousTouchPosition;

    Motherboard motherload;


};


#endif //MYGAME_DETAILIMAGE_H


