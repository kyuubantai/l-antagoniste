#ifndef __COMBAT__H
#define __COMBAT__H


#include "Heros.h"
#include "Ennemi.h"


class Combat{
    private:
        Heros heros;
        Ennemi ennemis[3]; // 3 ennemis max dans un combat
        int nbtour; // le nombre de tour, commencera à 1
        bool turn; // va déterminer le tour du héros ou des ennemis: true pour les héros, false pour les ennemis
    public:
        Combat();
        ~Combat();
        bool combat();
};

#endif