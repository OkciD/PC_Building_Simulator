#include <cocos/ui/UIHelper.h>
#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "ListWidget.h"
#include "mainClasses/DetailImage.h"

USING_NS_CC;

const int border = 2;
void setNodeSize(Node * const node, double const &width,
                 double const &height)
{
	node->setScaleX(static_cast<float>(width / node->getContentSize().width));
	node->setScaleY(static_cast<float>(height / node->getContentSize().height));
}

Scene* MainScene::createScene()
{
    return MainScene::create();
}

bool MainScene::init()
{
    this->scheduleUpdate();
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("main_scene_background_origin.jpg");
	background->setAnchorPoint(Vec2(0.5, 0.5));
	background->setPosition(Vec2(visibleSize.width/2 + origin.x,
	                             visibleSize.height/2 + origin.y));
	this->addChild(background, -10);

	auto title = Label::createWithTTF("PC Building Simulator",
	                                  "fonts/Orbitron.ttf", 24);
	title->setPosition(Vec2(origin.x + visibleSize.width/2,
	                        origin.y + visibleSize.height -
	                        title->getContentSize().height));
	title->setColor(Color3B(0, 0, 0));
	this->addChild(title, 1);

    auto closeItem = MenuItemImage::create("close_icon.png",
                                           "close_icon.png",
                                           CC_CALLBACK_1(
		                                           MainScene::menuCloseCallback,
		                                           this));
	setNodeSize(closeItem, 0.02 * visibleSize.width, 0.02 * visibleSize.width);
	closeItem->setAnchorPoint(Vec2(0, 1));
	closeItem->setPosition(Vec2(origin.x + border,
	                            origin.y - border + visibleSize.height));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	auto listWidget = ListWidget::create();
	this->addChild(listWidget, 1);

	auto header = ListHeaderItem::create("Motherboards", 40, Vec2(0, 0),
	                                     Vec2(200, 200),
	                                     Size(static_cast<float>(0.2 *
			                                     visibleSize.width), 70));
	this->addChild(header, 2);
	this->addChild(header->getLabel(), 3);

    std::string testDetailRes("test.png");
    auto CPUImage = DetailImage::create(testDetailRes);
    this->addChild(CPUImage, 1);
//    CPUImage->update(0.1);

//	auto touchListener = EventListenerTouchOneByOne::create();
//
//	touchListener->onTouchBegan = CC_CALLBACK_2(DetailImage::onTouchBegan, CPUImage);
//	touchListener->onTouchEnded = CC_CALLBACK_2(DetailImage::onTouchEnded, CPUImage);
//	touchListener->onTouchMoved = CC_CALLBACK_2(DetailImage::onTouchMoved, CPUImage);
//	touchListener->onTouchCancelled = CC_CALLBACK_2(DetailImage::onTouchCancelled, CPUImage);
//
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, CPUImage);


    return true;
}


void MainScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void MainScene::update( float dt ) {
//    DetailImage::update( dt );
//    CPUImage->update(0.1);
}
