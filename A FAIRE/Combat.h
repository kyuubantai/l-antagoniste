#ifndef __COMBAT__H
#define __COMBAT__H

#include "Heros.h"
#include "Ennemi.h"
#include "Competence.h"
#include <vector>


enum Tour {MOI,ENNEMI};

class Combat {
    private:
        Ennemi en1,en2,en3;
        vector<Ennemi> ennemis;
        void menu(Heros heros,int action);
        Ennemi selecteurEnnemi(int pos, vector<Ennemi> ennemis);
        Competence selecteurComp(int action,vector<Ennemi>ennemis);
        string selecteurObj(int action);
    public:
        Combat();
        Tour tour;
        void combat(Heros heros,int action);

};


#endif