#ifndef __COMBAT__H
#define __COMBAT__H

#include "Heros.h"

enum Tour {MOI,ENNEMI};

class Combat {
    public:
        Tour tour;
        void combat(Heros heros,int action);
        void menuPersoBase(Heros heros);

};


#endif