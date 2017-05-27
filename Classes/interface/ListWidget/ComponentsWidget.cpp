#include "ComponentsWidget.h"

#include "ui/CocosGUI.h"
#include "ListWidget.h"

ComponentsWidget* ComponentsWidget::create()
{
	ComponentsWidget *componentsWidget = new ComponentsWidget();

	if ( !componentsWidget->init() )
	{
		CC_SAFE_DELETE(componentsWidget);
		return nullptr;
	}

	componentsWidget->autorelease();
	componentsWidget->setInitOptions_();

	return componentsWidget;
}

bool ComponentsWidget::isActive()
{
	return isActive_;
}

void ComponentsWidget::activateOnMovingDown()
{
	isActive_ = true;

	auto parent = static_cast<ListWidget *>(this->getParent());
	auto clickedHeader =
			parent->getChildByTag(parent->getFirstBottomHeaderTag() - 1);

	this->setPosition(Vec2(parent->getContentSize().width,
	                       clickedHeader->getBoundingBox().getMinY() -
			                       parent->getMargin() -
			                       this->getContentSize().height));

	auto moveTo = MoveTo::create(duration,
	                             Vec2(clickedHeader->getBoundingBox().getMinX(),
	                                  this->getPosition().y));
	this->runAction(moveTo);
}

void ComponentsWidget::activateOnMovingUp()
{
	isActive_ = true;

	auto parent = static_cast<ListWidget *>(this->getParent());
	auto firstBottomHeader = parent->getChildByTag(parent->getFirstBottomHeaderTag());

	this->setPosition(Vec2(this->getContentSize().width,
			                 firstBottomHeader->getBoundingBox().getMaxY() +
					                 parent->getMargin()));

	auto moveTo = MoveTo::create(duration,
	                             Vec2(firstBottomHeader->getBoundingBox().getMinX(),
	                                  this->getPosition().y));
	this->runAction(moveTo);
}

void ComponentsWidget::activateOnClickingLast()
{
	isActive_ = true;

	auto parent = static_cast<ListWidget *>(this->getParent());

	this->setPosition(Vec2(this->getContentSize().width, parent->getMargin()));

	auto moveTo = MoveTo::create(duration,
	                             Vec2(parent->getMargin(), this->getPosition().y));
	this->runAction(moveTo);
}

void ComponentsWidget::deactivate()
{
	isActive_ = false;

	auto parent = static_cast<ListWidget *>(this->getParent());

	auto moveTo = MoveTo::create(duration,
	                             Vec2(parent->getContentSize().width +
			                                  parent->getMargin(),
	                                  this->getPosition().y));
	this->runAction(moveTo);
}

ComponentsWidget::ComponentsWidget():
		isActive_(false)
{}

void ComponentsWidget::setInitOptions_()
{
//	this->setBackGroundImage("green.png");
	this->setBackGroundColorType(ui::LAYOUT_COLOR_SOLID);
	this->setBackGroundColor(Color3B::GREEN);
//	this->_contentSize.width = this->getParent()->getContentSize().width -
//			2 * static_cast<ListWidget *>(this->getParent())->getMargin();
//	this->setVisible(false);
}