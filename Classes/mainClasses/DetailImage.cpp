//
// Created by sergey on 20.05.17.
//

#include "DetailImage.h"


DetailImage *DetailImage::create(const char *resDetailImage)
{


    DetailImage *DetailSprite = new DetailImage();

    if (DetailSprite && DetailSprite->initWithFile(resDetailImage))
    {

        DetailSprite->autorelease();

        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();

        DetailSprite->setAnchorPoint(Vec2(1, 1));
        DetailSprite->setPosition(origin.x + visibleSize.width / 2,
                                  origin.y + visibleSize.height / 2);

        DetailSprite->withToHeightRatio =
                static_cast<float>(DetailSprite->getContentSize().width) / DetailSprite->getContentSize().height;

        DetailSprite->setSize(
                static_cast<float >(0.2 * visibleSize.width) * DetailSprite->withToHeightRatio,
                static_cast<float >(0.2 * visibleSize.width)
        );

        DetailSprite->initOptions();

        DetailSprite->addEvents();

        return DetailSprite;
    }

    CC_SAFE_DELETE(DetailSprite);
    return NULL;

}

void DetailImage::initOptions()
{

}

void DetailImage::addEvents()
{
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = [&](cocos2d::Touch *touch, cocos2d::Event *event)
    {
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = this->getBoundingBox();

        if (rect.containsPoint(p))
        {
            mTouchMovePosition = p;
            return true; // to indicate that we have consumed it.
        }

        return false; // we did not consume this event, pass thru.
    };


    listener->onTouchCancelled = [=](cocos2d::Touch *touch, cocos2d::Event *event)
    {
        DetailImage::touchCancelledEvent(touch, event);
    };

    listener->onTouchMoved = [=](cocos2d::Touch *touch, cocos2d::Event *event)
    {
        DetailImage::moveEvent(touch, event);
    };

    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);
}


void DetailImage::touchCancelledEvent(cocos2d::Touch *touch, cocos2d::Event *_p)
{
    CCLOG("touched MySprite");
}

void DetailImage::moveEvent(cocos2d::Touch *touch, cocos2d::Event *_p)
{
    CCLOG("move MySprite");

    mPreviousTouchPosition = mTouchMovePosition;
    mTouchMovePosition = touch->getLocation();

    cocos2d::Vec2 delta = (mTouchMovePosition - mPreviousTouchPosition);
    Vec2 mNewPosition = this->getPosition() + delta;

    this->setPosition(mNewPosition);
}

