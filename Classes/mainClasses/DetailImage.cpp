//
// Created by sergey on 20.05.17.
//

#include "DetailImage.h"
#include "MainScene.h"

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

    listener->onTouchEnded = [=](cocos2d::Touch *touch, cocos2d::Event *event)
    {
        DetailImage::onTouchEnded(touch, event);
    };

    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);
}


void DetailImage::touchCancelledEvent(cocos2d::Touch *touch, cocos2d::Event *_p)
{
//    CCLOG("touched MySprite");
}

void DetailImage::moveEvent(cocos2d::Touch *touch, cocos2d::Event *_p)
{
//    CCLOG("move MySprite");

    mPreviousTouchPosition = mTouchMovePosition;
    mTouchMovePosition = touch->getLocation();

    cocos2d::Vec2 delta = (mTouchMovePosition - mPreviousTouchPosition);
    Vec2 mNewPosition = this->getPosition() + delta;

    this->setPosition(mNewPosition);
}
//
bool DetailImage::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *_p)
{
//    detail = "motherboard";
//
//    cocos2d::Vec2 p = touch->getLocation();
//    if (detail == "motherboard")
//    {
//        paintMotherboard(p);
//    }
//
//    if (detail == "storageDevice")
//    {
//        paintStorageDevice(p);
//    }
//
//    if (detail == "powerSupply")
//    {
//        paintPowerSupply(p);
//    }
//
//
}
//
//void DetailImage::paintMotherboard(cocos2d::Vec2 p)
//{
//    DetailMargin Margin(550, 850, 450, 530);
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//
//    double sizeOfDecorator = 300; // размер миниатюры
//
//    if (p.x >= Margin.x && p.x <= Margin.x + Margin.lenghtX && p.y <= Margin.y && p.y >= Margin.y - Margin.lenghtY)
//    {
//        const Size size = visibleSize / 12; // как считать этот коэффициент?
//
//        auto motherboard = Sprite::create("motherboard.jpg");
//        motherboard->setContentSize(size);
//        motherboard->setPosition(Margin.x - p.x, Margin.y - p.y);
//
//        this->addChild(motherboard, 1);
//
//        //   Carcass->addChild(processor, 1);
//    } else
//    {
//        //вычитаем сумму, ничего не делаем
//    }
//
//    //удалить изображение миниатюры
//
//}
//
//void DetailImage::paintStorageDevice(cocos2d::Vec2 p)
//{
//    DetailMargin Margin(1111, 623, 200, 70);
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//
//    double sizeOfDecorator = 300; // размер миниатюры
//
//    if (p.x >= Margin.x && p.x <= Margin.x + Margin.lenghtX && p.y <= Margin.y && p.y >= Margin.y - Margin.lenghtY)
//    {
//        const Size size = visibleSize / 12; // как считать этот коэффициент?
//
//        auto storageDevice = Sprite::create("storage.jpg");
//        storageDevice->setContentSize(size);
//        storageDevice->setPosition(Margin.x - p.x, Margin.y - p.y);
//
//        this->addChild(storageDevice, 1);
//
//        //   Carcass->addChild(processor, 1);
//    } else
//    {
//        //вычитаем сумму, ничего не делаем
//    }
//}
//
//void DetailImage::paintPowerSupply(cocos2d::Vec2 p)
//{
//    DetailMargin Margin(500, 300, 450, 200);
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//
//    double sizeOfDecorator = 300; // размер миниатюры
//
//    if (p.x >= Margin.x && p.x <= Margin.x + Margin.lenghtX && p.y <= Margin.y && p.y >= Margin.y - Margin.lenghtY)
//    {
//        const Size size = visibleSize / 12; // как считать этот коэффициент?
//
//        auto power = Sprite::create("block.jpg");
//        power->setContentSize(size);
//        power->setPosition(Margin.x - p.x, Margin.y - p.y);
//
//        this->addChild(power, 1);
//
//        //   Carcass->addChild(processor, 1);
//    } else
//    {
//        //вычитаем сумму, ничего не делаем
//    }
//}
