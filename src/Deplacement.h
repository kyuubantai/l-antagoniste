#ifndef __DEPLACEMENT__H
#define __DEPLACEMENT__H

#include "Monde.h"

class Deplacement {
    private:
        Monde monde;
        void interaction(); //Gestion de l'interaction avec les cartes
    public:
        void deplacement(); //Gestion du déplacement du perso sur la carte
};

#endif