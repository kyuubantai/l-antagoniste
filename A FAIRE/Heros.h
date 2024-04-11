#ifndef __HEROS__H
#define __HEROS__H

#include <string>
#include "Personnage.h"

using namespace std;

class Heros {
    public:
	    Personnage stats;
        string inventaire[10];
        Heros();
};

#endif