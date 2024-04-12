#ifndef __MONDE__H
#define __MONDE__H

#include "Carte.h"

/**
 * @class Monde
 * 
 * @brief Crée le l'environnement du jeu et conserve la position
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
        * et initialise les 12 Cartes individuellement.
        **/
        Monde();

        /**
         * @brief Récupère mX, la position horizontale actuelle.
        **/
        int getX();

        /**
         * @brief Récupère mY, la position verticale actuelle.
        **/
        int getY();

        /**
         * @brief Modifie la position horizontale mX actuelle.
         * @param nvX l'entier représentant la nouvelle position mX
        **/
        void setX(const int& nvX);

        /**
         * @brief Modifie la position horizontale mY actuelle.
         * @param nvY l'entier représentant la nouvelle position mY
        **/
        void setY(const int& nvY);

        /**
         * @brief Récupère mCarte la Carte actuelle.
        **/
        int getCarte() const;

        /**
         * @brief Modifie la Carte actuelle mCarte.
         * @param nvY l'entier représentant la nouvelle position mY
        **/
        void setCarte(const int& nvCarte);
};


#endif
