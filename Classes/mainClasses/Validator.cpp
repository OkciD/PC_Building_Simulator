
#include "Validator.h"
#include "Constants.h"

bool Validator::Validate(cocos2d::Vec2 p, MiniComponentImage *miniImage, ComponentImage *detailImage) {
    if (miniImage->GetType() != detailImage->GetType()) {
        return false;
    }
    return true;
//    if (miniImage->GetType() == MOTHERBOARD || miniImage->GetType() == POWER_SUPPLY || miniImage->GetType() == HDD) {
//        return validateCase(p, miniImage, detailImage);
//    } else
//    {
//        if(miniImage->GetType() == PROCESSOR || miniImage->GetType() == COOLING_DEVICE || miniImage->GetType() == RANDOM_ACCESS_MEMORY || miniImage->GetType() == VIDEOCARD) {
//            return validateCase(p, miniImage, detailImage); //другой метод
//        }
//        else
//        {
//            error(miniImage);
//            return false;
//        }
//    }
}

//bool Validator::validateCase(cocos2d::Vec2 p, MiniComponentImage *miniImage, ComponentImage *detailImage) {
//
//    cocos2d::Rect boundingBox = detailImage->getBoundingBox();
//    boundingBox.origin += detailImage->getParent()->getBoundingBox().origin;
//
//    return boundingBox.containsPoint(p);
//}

//void Validator::validateMotherboard(cocos2d::Vec2 p, MiniComponentImage *miniImage)
//{
//
//    //здесь проверяем только координаты, а остальное в Computer
//    int i = 0;
//
//    while (margins[i].type != miniImage->GetType()) {
//        i++;
//    }
//
//    margin detailMargin = margins[i];
//
//    if (p.x >= detailMargin.x && p.x <= detailMargin.x + detailMargin.lenghtX && p.y <= detailMargin.y && p.y >= detailMargin.y - detailMargin.lenghtY)
//    {
//        computer.AddOnMotherBoard(miniImage);
//    } else {
//        error(miniImage);
//    }
//}

void Validator::error(MiniComponentImage *miniImage) {

}