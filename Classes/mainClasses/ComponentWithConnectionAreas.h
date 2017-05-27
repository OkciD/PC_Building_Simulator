//
// Created by sergey on 26.05.17.
//

#ifndef MYGAME_COMPONENTWITHCONNECTIONAREAS_H
#define MYGAME_COMPONENTWITHCONNECTIONAREAS_H

#include "ComponentImage.h"

class ComponentWithConnectionAreas : public ComponentImage
{
public:
    ComponentWithConnectionAreas(ComponentTypes type, std::string resComponentImage)
            : ComponentImage(type, resComponentImage) {};

    static ComponentWithConnectionAreas *
    create(ComponentTypes type, std::string resComponentImage, Vec2 topLeftPoint, Vec2 RightBottomPoint);

//    void AddComponent(ComponentImage *component);
private:
    virtual void initOptions() {};

    virtual void addEvents() {};
};


#endif //MYGAME_COMPONENTWITHCONNECTIONAREAS_H
