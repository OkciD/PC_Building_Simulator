//
// Created by okcid_ on 10.05.17.
//

#include "ListHeaderItem.h"

ListHeaderItem* ListHeaderItem::create(const std::string &labelText,
                                       const float &fontSize,
                                       const Vec2 &anchorPoint,
                                       const Vec2 &position, const Size &size)
{
	ListHeaderItem *listHeaderItem = (ListHeaderItem *) CustomSprite::create("button_normal.png");
	listHeaderItem->label_ = Label::createWithTTF(labelText,
	                                              "fonts/GOST type A.ttf",
	                                              fontSize);

	listHeaderItem->setAnchorPoint(anchorPoint);
	listHeaderItem->setPosition(position);
	listHeaderItem->setAnchorPoint(Vec2(0, 0));
	listHeaderItem->setSize(size);

//	if ( label->getContentSize().width > size.width * 0.9 )
//	{
//		auto linebrokenLabelText = std::string(labelText);
//		std::replace(linebrokenLabelText.begin(), linebrokenLabelText.end(),
//		             ' ', '\n');
//		label->setString(linebrokenLabelText);
//	}

	listHeaderItem->label_->setAnchorPoint(Vec2(0.5, 0.5));
	Vec2 labelPosition;

	if ( anchorPoint.x == 0 )
		labelPosition.x = position.x + size.width/2;
	else if (anchorPoint.x == 1)
		labelPosition.x = position.x - size.width/2;
	else
		labelPosition.x = position.x;

	if ( anchorPoint.y == 0 )
		labelPosition.y = position.y + size.height/2;
	else if ( anchorPoint.y == 1 )
		labelPosition.y = position.y - size.height/2;
	else
		labelPosition.y = position.y;

	listHeaderItem->label_->setPosition(labelPosition);

	return listHeaderItem;
}

Label *ListHeaderItem::getLabel() const
{
	return label_;
}