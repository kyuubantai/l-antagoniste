#ifndef __MONDE__H
#define __MONDE__H

#include "Carte.h"

class Monde {
    private:
        int mX;
        int mY;
        int mCarteX;
        int mCarteY;
    public:
        Monde(); // Initialise toutes les cartes
        Carte tabCarte[3][4];
        int getX();
        int getY();
        void setX(const int& nvX);
        void setY(const int& nvY);
        int getCarteX() const;
        int getCarteY() const;
};


#endif
