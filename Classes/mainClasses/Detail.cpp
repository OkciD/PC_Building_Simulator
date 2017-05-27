//
// Created by evgenia on 24.05.17.
//

#include "Detail.h"


int Detail::GetRating()
{
    return performanceRating;
}

unsigned int Detail::GetPrice()
{
    return price;
}

Detail::Detail(ComponentTypes type, std::string resComponentImage)
: type(type), resComponentImage(resComponentImage)
{
    //HARDCODE!!!!!!!!!!YEAH
//    switch ( type ) {
//        case CARCAS:
//            performanceRating = 10;
//            price = 10;
//            size = CARCAS_SIZE;
//            position = CARCAS_POSITION;
//            break;
//        case POWER_SUPPLY:
//            performanceRating = 20;
//            price = 20;
//            size;
//            position;
//            break;
//        case PROCESSOR:
//            performanceRating = 30;
//            price = 30;
//            size;
//            position;
//            break;
//        case COOLING_DEVICE:
//            performanceRating = 40;
//            price = 40;
//            size;
//            position;
//            break;
//        case RANDOM_ACCESS_MEMORY:
//            performanceRating = 50;
//            price = 50;
//            size;
//            position;
//            break;
//        case VIDEOCARD:
//            performanceRating = 60;
//            price = 60;
//            size;
//            position;
//            break;
//        case HDD:
//            performanceRating = 70;
//            price = 70;
//            size;
//            position;
//            break;
//        case MOTHERBOARD:
//            performanceRating = 100;
//            price = 100;
//            size = MOTHERBOARD_SIZE;
//            position = MOTHERBOARD_POSITION;
//            break;
//        default:
//            assert(true);
//            break;
//    }



}
