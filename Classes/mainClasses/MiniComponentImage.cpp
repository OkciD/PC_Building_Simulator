

#include "Validator.h"


MiniComponentImage *MiniComponentImage::create(ComponentTypes type, std::string resComponentImage,
                                               Vec2 position)   //, ComponentWithConnectionAreas carcas)
{
    MiniComponentImage *ComponentSprite = new MiniComponentImage(type, resComponentImage);

    if (ComponentSprite && ComponentSprite->initWithFile(resComponentImage))
    {

        ComponentSprite->autorelease();

        ComponentSprite->setAnchorPoint(Vec2(0, 0));
        ComponentSprite->setSize(300.0, 300.0);
        ComponentSprite->setPosition(position.x, position.y);

        ComponentSprite->initOptions();

        ComponentSprite->addEvents();

        return ComponentSprite;
    }

    CC_SAFE_DELETE(ComponentSprite);
    return NULL;
}


void MiniComponentImage::initOptions()
{

}


void MiniComponentImage::addEvents()
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
            return true;
        }

        return false;
    };


    listener->onTouchCancelled = [=](cocos2d::Touch *touch, cocos2d::Event *event)
    {
        MiniComponentImage::touchCancelledEvent(touch, event);
    };

    listener->onTouchMoved = [=](cocos2d::Touch *touch, cocos2d::Event *event)
    {
        MiniComponentImage::moveEvent(touch, event);
    };

    listener->onTouchEnded = [=](cocos2d::Touch *touch, cocos2d::Event *event)
    {
        MiniComponentImage::onTouchEnded(touch, event);
    };

    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);
}

void MiniComponentImage::touchCancelledEvent(cocos2d::Touch *touch, cocos2d::Event *_p)
{

};


void MiniComponentImage::moveEvent(cocos2d::Touch *touch, cocos2d::Event *_p)
{
    mPreviousTouchPosition = mTouchMovePosition;
    mTouchMovePosition = touch->getLocation();

    cocos2d::Vec2 delta = (mTouchMovePosition - mPreviousTouchPosition);
    Vec2 mNewPosition = this->getPosition() + delta;

    this->setPosition(mNewPosition);
}

bool MiniComponentImage::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *_p)
{
    Node *carcas = this->getParent()->getChildByName("Carcas");
    Vec2 p = touch->getLocation();


    if (carcas->getBoundingBox().containsPoint(p))
    {
        mTouchMovePosition = p;
        ComponentImage *elem = (ComponentImage *) checkIntersection(p, carcas);
        if (elem!= nullptr)
        {
            Validator validator;
            if (validator.Validate(p, this, elem) )
            {
//                auto texture = SpriteFrameCache::getInstance()->getSpriteFrameByName("test");;
                elem->setTexture(this->getTexture());
            }
            CCLOG("true");
        }
        CCLOG("?");
        return true;
    }
    CCLOG("false");
    return false;
}

Node *MiniComponentImage::checkIntersection(Vec2 p, Node *component)
{
    for (auto elem : component->getChildren())
    {
        CCLOG("+");
        cocos2d::Rect boundingBox = elem->getBoundingBox();
        boundingBox.origin += component->getBoundingBox().origin;

        if (boundingBox.containsPoint(p))
        {
            return elem;
        }
    }
    return nullptr;
}
