#ifndef __MONDE__H
#define __MONDE__H

#include "Carte.h"

/**
 * @class Monde
 * 
 * @brief Classe Monde créant le l'environnement du jeu et conserve la position
 * mx, my du personnage se déplaçant ainsi que la Carte mCarte où il se trouve.
 **/

class Monde {
    private:
        int mX;
        int mY;
        int mCarte;
    public:

        Carte tabCarte[12];

        /**
        * @brief Constructeur de la classe : initialise mX,mY et mCarte comme position initiale
        * et initialise les 12 Cartes individuellement
        **/
        Monde();

        /**
         * @brief Récupère la position mX actuelle
         * @return mX la position actuelle
        */

        int getX();
        int getY();
        void setX(const int& nvX);
        void setY(const int& nvY);
        int getCarte() const;
        void setCarte(const int& nvCarte);
};


#endif
