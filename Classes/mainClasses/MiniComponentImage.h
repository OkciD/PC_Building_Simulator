//
// Created by sergey on 20.05.17.
//

#ifndef MYGAME_DETAILIMAGE_H
#define MYGAME_DETAILIMAGE_H


#include "ComponentWithConnectionAreas.h"
#include "Detail.h"
//#include "../mainClasses/PC_Components/Motherboard.h"


USING_NS_CC;


class MiniComponentImage : public ComponentImage
{
public:

//    MiniComponentImage(ComponentTypes type, std::string resComponentImage, ComponentWithConnectionAreas carcas)
//            : ComponentImage(type, resComponentImage), carcas(carcas) {};

    MiniComponentImage(ComponentTypes type, std::string resComponentImage)
            : ComponentImage(type, resComponentImage) {};


    ~MiniComponentImage() {};

    static MiniComponentImage *
    create(ComponentTypes type, std::string resComponentImage, Vec2 position);// , ComponentWithConnectionAreas carcas);

private:
    void initOptions();

    void addEvents();

    void touchCancelledEvent(cocos2d::Touch *touch, cocos2d::Event *_p);

    void moveEvent(cocos2d::Touch *touch, cocos2d::Event *_p);

    bool onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *_p);

    Node *checkIntersection(Vec2 p, Node *component);

    float withToHeightRatio = 0;

    Vec2 mTouchMovePosition;

    Vec2 mPreviousTouchPosition;
};


#endif //MYGAME_DETAILIMAGE_H


