#ifndef __HEROS__H
#define __HEROS__H

#include <string>
#include "Personnage.h"

using namespace std;


/**
 * @class Heros
 *
 * @brief Statistiques du personnage et inventaire.
 **/
class Heros {
    public:
	    Personnage stats;
        string inventaire[10];

        /**
         * @brief Constructeur de la classe : initialise les statistiques du héros.
         **/
        Heros();
};

#endif