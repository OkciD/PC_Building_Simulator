//
// Created by sergey on 26.05.17.
//

#include "ComponentImage.h"

ComponentImage *ComponentImage::create(ComponentTypes type, std::string resComponentImage, Vec2 topLeftPoint, Vec2 rightBottomPoint)
{
    ComponentImage *ComponentSprite = new ComponentImage(type, resComponentImage);

    if (ComponentSprite && ComponentSprite->initWithFile(resComponentImage))
    {

        ComponentSprite->autorelease();

        ComponentSprite->setAnchorPoint(Vec2(0, 0));
        ComponentSprite->setContentSize(Size(rightBottomPoint.x - topLeftPoint.x, topLeftPoint.y - rightBottomPoint.y));
        ComponentSprite->setPosition(topLeftPoint.x, rightBottomPoint.y);

        ComponentSprite->initOptions();

        ComponentSprite->addEvents();

        return ComponentSprite;
    }

    CC_SAFE_DELETE(ComponentSprite);
    return NULL;
}

//void ComponentImage::AddComponent(ComponentImage *component)
//{
//    this->addChild(component, 1);
//}



