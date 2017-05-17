//
// Created by okcid_ on 10.05.17.
//

#ifndef MYGAME_CUSTOMSPRITE_H
#define MYGAME_CUSTOMSPRITE_H

#include "cocos2d.h"

USING_NS_CC;

class CustomSprite: public cocos2d::Sprite
{
public:
	static CustomSprite *create(const std::string &fileName);
	void setSize(const float &width, const float &height);
	void setSize(const Size &size);
};


#endif //MYGAME_CUSTOMSPRITE_H
