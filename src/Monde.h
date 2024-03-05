#ifndef __MONDE__H
#define __MONDE__H

#include "Carte.h"

class Monde {
    private:
        int x;
        int y;
    public:
        Carte tabCarte[];
        int getX();
        int getY();
        void setX(const int& nvX);
        void setY(const int& nvY);
};


#endif