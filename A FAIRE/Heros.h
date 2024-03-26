#ifndef __HEROS__H
#define __HEROS__H

#include "Personnage.h"
#include "Objet.h"
using namespace std;

class Heros {
    public:
	    Personnage stats;
        Objet invetaire[10];
        Heros();
};

#endif