//
// Created by sergey on 26.05.17.
//

#include "ComponentWithConnectionAreas.h"

//void ComponentWithConnectionAreas::AddComponent(ComponentImage *component)
//{
//    this->addChild(component, 1);
//}


ComponentWithConnectionAreas *
ComponentWithConnectionAreas::create(ComponentTypes type, std::string resComponentImage, Vec2 topLeftPoint,
                                     Vec2 rightBottomPoint)
{
    ComponentWithConnectionAreas *ComponentSprite = new ComponentWithConnectionAreas(type, resComponentImage);

    if (ComponentSprite && ComponentSprite->initWithFile(resComponentImage))
    {

        ComponentSprite->autorelease();

        ComponentSprite->setAnchorPoint(Vec2(0, 0));
        ComponentSprite->setSize(rightBottomPoint.x - topLeftPoint.x, topLeftPoint.y - rightBottomPoint.y);
        ComponentSprite->setPosition(topLeftPoint.x, rightBottomPoint.y);

        ComponentSprite->initOptions();

        ComponentSprite->addEvents();

        switch (type)
        {
            case CARCAS:
            {
                auto hdd = ComponentImage::create(HDD, "button_normal.png", Vec2(706.0, 610.0), Vec2(906.0, 574.0));
                ComponentSprite->addChild(hdd, 0);


                auto powerSupply = ComponentImage::create(POWER_SUPPLY, "button_normal.png", Vec2(61.0, 236.0),
                                                          Vec2(346.0, 115.0));
                ComponentSprite->addChild(powerSupply, 0);


                auto motherboard = ComponentWithConnectionAreas::create(MOTHERBOARD, "button_normal.png",
                                                                        Vec2(90.0, 915.0), Vec2(552.0, 330.0));
                ComponentSprite->addChild(motherboard, 0);

                break;
            }
            case MOTHERBOARD:
                break;

            default:
                break;
        }

        return ComponentSprite;
    }

    CC_SAFE_DELETE(ComponentSprite);
    return NULL;
}