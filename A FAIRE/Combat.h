#ifndef __COMBAT__H
#define __COMBAT__H

#include "Heros.h"
#include "Ennemi.h"
#include "Competence.h"
#include <vector>


enum Tour {MOI,ENNEMI};
enum Etat{MENUBASE,SELECT,COMP,OBJ,GUARD,RETREAT};
enum EtatComp{MENUCOMP,MONO,MULTI,HEAL};


/**
 * @class Combat
 *
 * @brief Gère les combats.
 **/
class Combat {
    private:
        Ennemi en;
        vector<Ennemi> ennemis;
        void menu(Heros heros,int action);
        Ennemi selecteurEnnemi(int pos, vector<Ennemi> ennemis);
        void selecteurComp(int action,vector<Ennemi>ennemis,Heros h);
        Etat saisirchoix(int choice);
        EtatComp saisirComp(int choice);
        string selecteurObj(int pos,Heros h);
    public:
        Combat();
        ~Combat();
        Etat etat;
        EtatComp et;
        bool fin;
        Tour tour;
        void combat(Heros heros,int action);

};


#endif