#include "ListWidget.h"

const int border = 5;
const float headersToWidgetRatio = 0.45;

ListWidget *ListWidget::create()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	ListWidget *listWidget = new ListWidget();

	if ( !listWidget->initWithFile("list_widget_background.jpg") )
	{
		CC_SAFE_DELETE(listWidget);
		return nullptr;
	}

	listWidget->autorelease();
	listWidget->setContentSize(
			Size(static_cast<float>(0.2 * visibleSize.width),
			     visibleSize.height - border - border));

	listWidget->createComponentsWidget_();
	listWidget->fill_();

	return listWidget;
}

void ListWidget::activateHeader(int clickedHeaderTag)
{
	Vec2 headerPosition;
	headerPosition.x = this->getContentSize().width / 2;

	if ( clickedHeaderTag == firstBottomHeaderTag_ - 1 )
	{
		if ( componentsWidget_->isActive() )
		{
			componentsWidget_->deactivate();

			headerPosition.y = this->getChildByTag(firstBottomHeaderTag_ - 1)->
					getBoundingBox().origin.y - margin_;

			Vector<Node *>::iterator headersIterator =
					this->getChildren().begin() + 1 + firstBottomHeaderTag_;
			for ( ; headersIterator != this->getChildren().end();
			        headersIterator++ )
			{
				auto moveTo = MoveTo::create(duration, headerPosition);
				(*headersIterator)->runAction(moveTo);
				headerPosition.y -=
						(*headersIterator)->getContentSize().height +
						margin_;

			}

			firstBottomHeaderTag_ = this->getChildren().size() - 1;
			return;
		}
		else
		{
			componentsWidget_->activateOnClickingLast();
		}
	}
	else if ( clickedHeaderTag < firstBottomHeaderTag_ )
	{
		headerPosition.y = this->getChildByTag(firstBottomHeaderTag_ - 1)->
				getContentSize().height + margin_;
		if ( firstBottomHeaderTag_ != this->getChildrenCount() - 1 )
			headerPosition.y += this->getChildByTag(firstBottomHeaderTag_)->
					getBoundingBox().getMaxY();

		Vector<Node *>::iterator headersIterator =
				this->getChildren().begin() + firstBottomHeaderTag_;
		for ( ; (*headersIterator)->getTag() > clickedHeaderTag ;
		        headersIterator-- )
		{
			auto moveTo = MoveTo::create(duration, headerPosition);
			(*headersIterator)->runAction(moveTo);
			headerPosition.y += (*headersIterator)->getContentSize().height +
					margin_;
		}

		firstBottomHeaderTag_ = clickedHeaderTag + 1;
		componentsWidget_->activateOnMovingDown();
	}
	else
	{
		headerPosition.y = this->getChildByTag(firstBottomHeaderTag_ - 1)->
				getBoundingBox().origin.y - margin_;

		Vector<Node *>::iterator headersIterator =
				this->getChildren().begin() + firstBottomHeaderTag_ + 1;
		for ( ; (headersIterator != this->getChildren().end()) &&
				        ((*headersIterator)->getTag() <= clickedHeaderTag);
		        headersIterator++)
		{
			auto moveTo = MoveTo::create(duration, headerPosition);
			(*headersIterator)->runAction(moveTo);
			headerPosition.y -= (*headersIterator)->getContentSize().height +
			                    margin_;

		}

		firstBottomHeaderTag_ = clickedHeaderTag + 1;
		if ( firstBottomHeaderTag_ == this->getChildrenCount() - 1 )
			componentsWidget_->activateOnClickingLast();
		else
			componentsWidget_->activateOnMovingUp();
	}
}

const float ListWidget::getMargin() const
{
	return margin_;
}

const int ListWidget::getFirstBottomHeaderTag() const
{
	return firstBottomHeaderTag_;
}

ListWidget::ListWidget():
		firstBottomHeaderTag_(-1), componentsWidget_(nullptr)
{}

void ListWidget::fill_()
{
	std::vector<std::string> headerTexts = {"Motherboards", "Processors",
	                                        "Coolers", "RAM", "Power supplies",
	                                        "HDD/SSD", "Graphics"};
	std::vector<std::string>::iterator headerTextsIterator = headerTexts.begin();
	int headerTag = 0;
	const float headerHeight =
			(headersToWidgetRatio * this->getContentSize().height -
			 (headerTexts.size() + 1) * margin_) / (headerTexts.size());
	const Vec2 headerAnchorPoint(0.5, 1);
	Vec2 headerPosition(this->getContentSize().width/2,
	                    this->getContentSize().height - margin_);
	const Size headerSize(this->getContentSize().width - margin_ - margin_,
	                      headerHeight);

	for ( ; headerTextsIterator != headerTexts.end(); headerTextsIterator++ )
	{
		auto headerItem =
				ListHeaderItem::create(*headerTextsIterator, 35, headerAnchorPoint,
				                       headerPosition, headerSize);
		this->addChild(headerItem, 2, headerTag);
		headerPosition.y -= headerSize.height + margin_;
		++headerTag;
	}

	this->firstBottomHeaderTag_ = headerTag;
}

void ListWidget::createComponentsWidget_()
{
	componentsWidget_ = ComponentsWidget::create();
	auto sizeOfThis = this->getBoundingBox().size;
	componentsWidget_->setContentSize(Size(sizeOfThis.width - 2 * margin_,
	                                       (1 - headersToWidgetRatio) *
			                                       sizeOfThis.height - margin_));
	componentsWidget_->setAnchorPoint(Vec2(0, 0));
	componentsWidget_->setPosition(Vec2(this->getContentSize().width + margin_,
	                                    margin_));
	this->addChild(componentsWidget_, 1);
}