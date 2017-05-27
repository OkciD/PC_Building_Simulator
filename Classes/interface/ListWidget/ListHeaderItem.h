#ifndef MYGAME_LISTHEADERITEM_H
#define MYGAME_LISTHEADERITEM_H

#include "cocos2d.h"
USING_NS_CC;

class ListHeaderItem: public Sprite
{
public:
	static ListHeaderItem *create(const std::string &labelText,
	                              const float &fontSize,
	                              const Vec2 &anchorPoint, const Vec2 &position,
	                              const Size &size);
	virtual ~ListHeaderItem() {};

private:
	void setInitOptions_(const Vec2 &anchorPoint, const Vec2 &position,
	                     const Size &size);
	void addEvents_();
	void addLabel_(const std::string &labelText, const float &fontSize);
	void fitLabel_(Label *const label);
};


#endif //MYGAME_LISTHEADERITEM_H
