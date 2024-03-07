#ifndef __ENNEMI__H
#define __ENNEMI__H

#include "Personnage.h"
using namespace std;

class Ennemi {
	public:
		Personnage mob;	
		Ennemi();
		~Ennemi();
		Personnage boss();
		Personnage tank();
		Personnage light();
};

#endif