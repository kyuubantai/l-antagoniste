#ifndef __HEROS__H
#define __HEROS__H

#include <string>
#include "Personnage.h"

using namespace std;

class Heros {
    private:
        Personnage stats;
        string invetaire[10];
    public:
        Heros();
        Personnage getStats() const;
        void setStats(Personnage stats);
};

#endif