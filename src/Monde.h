#ifndef __MONDE__H
#define __MONDE__H

#include "Carte.h"

class Monde {
    private:
        int current_x;
        int current_y;
    public:
        Carte tabCarte[];
        int getX();
        int getY();
        void setX(const int new_x);
        void setY(const int new_y);
};


#endif