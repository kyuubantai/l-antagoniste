#ifndef __COMBAT__H
#define __COMBAT__H


#include "Heros.h"
#include "Ennemi.h"

enum TOUR{Hero, Ennemies};

class Combat{
    private:
        Heros hero;
        Ennemi ennemies[3]; // 3 ennemis max dans un combat
        int nbtour; // le nombre de tour, commencera à 1
        TOUR turn; // va déterminer le tour du héros ou des ennemis: true pour les héros, false pour les ennemis
    public:
        Combat();
        ~Combat();
        bool combat();
};

#endif