//
// Created by sergey on 20.05.17.
//

#ifndef MYGAME_DETAILIMAGE_H
#define MYGAME_DETAILIMAGE_H


#include "CustomSprite.h"
#include "ListHeaderItem.h"

USING_NS_CC;

class DetailImage : public CustomSprite {

public:
//
    DetailImage() {};

    ~DetailImage() {};

    static DetailImage *create( std::string &resDetailImage );

    void initOptions();

    void addEvents();

    void touchCancelledEvent( cocos2d::Touch *touch, cocos2d::Event *_p );

    void moveEvent( cocos2d::Touch *touch, cocos2d::Event *_p );


private:
    float withToHeightRatio = 0;

    std::string resDetailImage;

    Vec2 mTouchMovePosition;

    Vec2 mPreviousTouchPosition;
};


#endif //MYGAME_DETAILIMAGE_H
