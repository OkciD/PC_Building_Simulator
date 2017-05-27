#include "ListHeaderItem.h"
#include "ListWidget.h"

const float defaultFontSize = 40;

ListHeaderItem* ListHeaderItem::create(const std::string &labelText,
                                       const float &fontSize,
                                       const Vec2 &anchorPoint,
                                       const Vec2 &position, const Size &size)
{
	ListHeaderItem *listHeaderItem = new ListHeaderItem();

	if ( !listHeaderItem->initWithFile("button_normal.png") )
	{
		CC_SAFE_DELETE(listHeaderItem);
		return nullptr;
	}

	listHeaderItem->autorelease();
	listHeaderItem->setInitOptions_(anchorPoint, position, size);
	listHeaderItem->addLabel_(labelText, fontSize);
	listHeaderItem->addEvents_();

	return listHeaderItem;
}

void ListHeaderItem::setInitOptions_(const Vec2 &anchorPoint,
                                     const Vec2 &position, const Size &size)
{
	this->setAnchorPoint(anchorPoint);
	this->setPosition(position);
	this->setContentSize(size);

}

void ListHeaderItem::addLabel_(const std::string &labelText,
                               const float &fontSize)
{
	auto label = Label::createWithTTF(labelText, "fonts/GOST type A.ttf",
	                                  defaultFontSize);

	label->setAnchorPoint(Vec2(0.5, 0.5));
	label->setPosition(this->getContentSize().width/2,
	                   this->getContentSize().height/2);
	this->addChild(label);
	this->fitLabel_(label);
}

void ListHeaderItem::fitLabel_(Label *const label)
{
	for ( float scale = 0.9;
	      (label->getBoundingBox().size.width >= this->getBoundingBox().size.width) ||
			      (label->getBoundingBox().size.height >= this->getBoundingBox().size.height);
	      scale -= 0.1)
	{
		label->setScale(scale);
	}
}

void ListHeaderItem::addEvents_()
{
	auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);

	touchListener->onTouchBegan = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		cocos2d::Vec2 touchPoint = touch->getLocation();
		cocos2d::Rect boundingBox = this->getBoundingBox();
		boundingBox.origin += this->getParent()->getBoundingBox().origin;

		return boundingBox.containsPoint(touchPoint);
	};

	touchListener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		static_cast<ListWidget *>(this->getParent())->
				activateHeader(this->getTag());
	};

	cocos2d::Director::getInstance()->getEventDispatcher()->
			addEventListenerWithFixedPriority(touchListener, 30);
}

