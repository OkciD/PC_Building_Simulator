//
// Created by evgenia on 24.05.17.
//

#ifndef MYGAME_DETAIL_H
#define MYGAME_DETAIL_H

class Detail
{
public:
    Detail() {}

    ~Detail() {}

    int GetRating();

    unsigned int GetPrice();

private:
    int performanceRating;

    unsigned int price;
};


#endif //MYGAME_DETAIL_H
