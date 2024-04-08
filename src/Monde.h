#ifndef __MONDE__H
#define __MONDE__H

#include "Carte.h"

class Monde {
    private:
        int mX;
        int mY;
        int mCarte;
    public:
        Monde(); // Initialise toutes les cartes
        Carte tabCarte[12];
        int getX();
        int getY();
        void setX(const int& nvX);
        void setY(const int& nvY);
        int getCarte() const;
        void setCarte(const int& nvCarte);
};


#endif
