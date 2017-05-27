#ifndef MYGAME_LISTWIDGET_H
#define MYGAME_LISTWIDGET_H

#include "ListHeaderItem.h"
#include "ComponentsWidget.h"

const float duration = 0.5;

class ListWidget: public cocos2d::Sprite
{
public:
	static ListWidget *create();
	void activateHeader(int clickedHeaderTag);
	const float getMargin() const;
	const int getFirstBottomHeaderTag() const;
	virtual ~ListWidget() {};

private:
	ListWidget();
	void fill_();
	void createComponentsWidget_();

	int firstBottomHeaderTag_;
	static constexpr float margin_ = 10;
	ComponentsWidget *componentsWidget_;
};

#endif //MYGAME_LISTWIDGET_H
