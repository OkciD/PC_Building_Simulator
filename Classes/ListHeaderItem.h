//
// Created by okcid_ on 10.05.17.
//

#ifndef MYGAME_LISTHEADERITEM_H
#define MYGAME_LISTHEADERITEM_H

#include "CustomSprite.h"
USING_NS_CC;

class ListHeaderItem: public CustomSprite
{
public:
	static ListHeaderItem *create(const std::string &labelText,
	                              const float &fontSize,
	                              const Vec2 &anchorPoint, const Vec2 &position,
	                              const Size &size);
	Label *getLabel() const;
private:
	Label *label_;
};


#endif //MYGAME_LISTHEADERITEM_H
