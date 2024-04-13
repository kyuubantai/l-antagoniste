#ifndef __ENNEMI__H
#define __ENNEMI__H

#include "Personnage.h"
using namespace std;


/**
 * @class Ennemi
 *
 * @brief Statistiques des ennemis.
 **/
class Ennemi {
	public:
		Personnage stats;

        /**
         * @brief Constructeur de la classe : initialise les statistiques des ennemis.
         **/
		Ennemi();

};

#endif