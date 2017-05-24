#include "ListWidget.h"

USING_NS_CC;

const int border = 2;

ListWidget *ListWidget::create()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	ListWidget *listWidgetSprite = (ListWidget *)
									CustomSprite::create("button_normal.png");
	listWidgetSprite->setAnchorPoint(Vec2(1, 1));
	listWidgetSprite->setPosition(origin.x + visibleSize.width - border,
	                              origin.y + visibleSize.height - border);
	listWidgetSprite->setSize(static_cast<float>(0.2 * visibleSize.width),
	                          visibleSize.height);

	return listWidgetSprite;
}