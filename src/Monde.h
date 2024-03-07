#ifndef __MONDE__H
#define __MONDE__H

#include "Carte.h"

class Monde {
    private:
        int mX;
        int mY;
        Carte tabCarte[3][4];
    public:
        Monde(); // Initialise toutes les cartes
        int getX();
        int getY();
        void setX(const int& nvX);
        void setY(const int& nvY);
};


#endif