//
// Created by sergey on 25.05.17.
//

#include "CarcasImage.h"

CarcasImage *CarcasImage::create(const char *resCarcasImage)
{
    CarcasImage *DetailSprite = new CarcasImage();

    if (DetailSprite && DetailSprite->initWithFile(resCarcasImage))
    {

        DetailSprite->autorelease();

        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();

        DetailSprite->setAnchorPoint(Vec2(1, 1));

        float withToHeightRatio =
                static_cast<float>(DetailSprite->getContentSize().width) / DetailSprite->getContentSize().height;

        DetailSprite->setSize(
                static_cast<float >(0.45 * visibleSize.width) * withToHeightRatio,
                static_cast<float >(0.45 * visibleSize.width)
        );
//
        DetailSprite->setPosition(origin.x + DetailSprite->getContentSize().width + 100,
                                  origin.y + DetailSprite->getContentSize().height);
//        DetailSprite->initOptions();
//
//        DetailSprite->addEvents();


        auto motherBoard = DetailImage::create("processor.jpg");
        motherBoard->setSize(
                static_cast<float >(0.4375 * DetailSprite->getContentSize().width),
                static_cast<float >(0.55 * DetailSprite->getContentSize().height)
        );
        motherBoard->setPosition((float) (DetailSprite->getContentSize().width * 0.51),
                                 (float) (DetailSprite->getContentSize().height * 0.85));
        DetailSprite->addChild(motherBoard);

        auto powerSupply = DetailImage::create("processor.jpg");
        powerSupply->setSize(
                static_cast<float >(0.27 * DetailSprite->getContentSize().width),
                static_cast<float >(0.12 * DetailSprite->getContentSize().height)
        );
        powerSupply->setPosition((float) (DetailSprite->getContentSize().width * 0.33),
                                 (float) (DetailSprite->getContentSize().height * 0.24));
        DetailSprite->addChild(powerSupply);


        return DetailSprite;
    }

    CC_SAFE_DELETE(DetailSprite);
    return NULL;
}
