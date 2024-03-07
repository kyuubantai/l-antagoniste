#ifndef __ENNEMI__H
#define __ENNEMI__H

#include "Personnage.h"
using namespace std;

class Ennemi {
	private:
		Personnage mob;	
	public:
		Ennemi();
		~Ennemi();
		Personnage boss();
		Personnage tank();
		Personnage light();
};

#endif