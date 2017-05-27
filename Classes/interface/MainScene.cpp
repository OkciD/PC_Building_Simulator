#include <cocos/ui/UIHelper.h>
#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "interface/ListWidget/ListWidget.h"

USING_NS_CC;

const int border = 5;
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
	this->addChild(title);

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
    this->addChild(menu);

	auto listWidget = ListWidget::create();
	listWidget->setAnchorPoint(Vec2(1, 1));
	listWidget->setPosition(origin.x + visibleSize.width - border,
	                        origin.y + visibleSize.height - border);
	this->addChild(listWidget);

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
