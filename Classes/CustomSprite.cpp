//
// Created by okcid_ on 10.05.17.
//

#include "CustomSprite.h"

CustomSprite *CustomSprite::create( const std::string &fileName ) {
    return ( CustomSprite * ) cocos2d::Sprite::create( fileName );
}

void CustomSprite::setSize( const float &width, const float &height ) {
    this->setScaleX( static_cast<float>(width / this->getContentSize().width) );
    this->setScaleY( static_cast<float>(height / this->getContentSize().height) );
}

void CustomSprite::setSize( const Size &size ) {
    this->setScaleX( size.width / this->getContentSize().width );
    this->setScaleY( size.height / this->getContentSize().height );
}