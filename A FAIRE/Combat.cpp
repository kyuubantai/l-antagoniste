#include "Combat.h"
#include <iostream>
#include <vector>

using namespace std;


enum Etat{MENUBASE,SELECT,COMP,OBJ}; 


Combat::Combat(){
    tour = MOI;
    ennemis.push_back(en1);
    ennemis.push_back(en2);
    ennemis.push_back(en3);
}
Ennemi selecteurEnnemi(int pos, vector<Ennemi> ennemis){
    switch (pos)
    {
    case 0:
        return ennemis[0];
        break;
    case 1:
        return ennemis[1];
        break;
    case 2:
        return ennemis[2];
        break;
    default:
        break;
    }
}


void Combat::menu(Heros hero, int action){
    //bool garde = false;
    Etat etat;
    if(etat == MENUBASE){
        switch (action)
        {

        case 1: // Attaque basique
            etat = SELECT;
            Ennemi select = selecteurEnnemi(action,ennemis);
            break;
        
        case 2: // Garde
            //garde = true;
            //hero.stats.def*=1.2;
            break;
        
        case 3 : // Compétences
            etat = COMP;
            //Competence select = selecteurComp(action,ennemis);
            break;

        case 4 : // Objets
            etat = OBJ;
            //string select = selecteurObj(action);
            break;
        case 0 : // Retraite 
            //fin = true
            break;
        
        default:
            break;
        }
    }
    
}

/*void Combat::combat(Heros heros, int action){
    bool fin=false;
    int menu;
    char n;
    while(!fin){
        if(tour == MOI) menuPersoBase(heros,action);
        else{
            cout <<"Ennemi"<<endl;
            heros.stats.vie -10;
        }


        if (tour == MOI) tour = ENNEMI;
	    else tour = MOI;
        if(heros.stats.vie==0 || ennemis[].getVie()==0){
            fin=true;
        }
    }
    if(heros.stats.vie<=0){cout<<"défaite"<<endl;}
    if(en.stats.getVie()<=0){cout<<"victoire"<<endl;}
}*/