//
// Created by sergey on 26.05.17.
//

#ifndef MYGAME_MINICOMPONENTIMAGE_H
#define MYGAME_MINICOMPONENTIMAGE_H

#include "CustomSprite.h"
#include "string.h"
#include "Constants.h"

class ComponentImage : public CustomSprite
{
public:
    ComponentImage(ComponentTypes type, std::string resComponentImage)
            : type(type), resComponentImage(resComponentImage) {}

    ~ComponentImage() {};

    static ComponentImage *
    create(ComponentTypes type, std::string resComponentImage, Vec2 topLeftPoint, Vec2 RightBottomPoint);

    ComponentTypes GetType() { return type; };

    bool IsEmpty() { return empty; };
protected:
    ComponentTypes type;

    std::string resComponentImage;

private:
    bool empty = true;

    virtual void initOptions() {};

    virtual void addEvents() {};
};


#endif //MYGAME_MINICOMPONENTIMAGE_H
