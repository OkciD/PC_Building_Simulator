#ifndef MYGAME_COMPONENTSWIDGET_H
#define MYGAME_COMPONENTSWIDGET_H

#include <cocos/ui/UIListView.h>
#include "cocos2d.h"

USING_NS_CC;



class ComponentsWidget: public ui::ListView
{
public:
	static ComponentsWidget *create();
	bool isActive();
	void activateOnMovingDown();
	void activateOnMovingUp();
	void activateOnClickingLast();
	void deactivate();

private:
	ComponentsWidget();
	void setInitOptions_();

	bool isActive_;
};


#endif //MYGAME_COMPONENTSWIDGET_H
