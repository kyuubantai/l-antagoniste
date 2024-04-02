#include "Combat.h"
#include <iostream>
#include <vector>

using namespace std;

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

//int getAction() return action
void Combat::menuPersoBase(Heros hero, int action){
    switch (action)
    {
    
    case 1:  // Attaque basique
        int action2;
        break;
    
    case 2: // Garde

        break;
    
    case 3 : // Compétences

        break;

    case 4 : // Objets

        break;
    case 0 : // Retraite 

        break;
    
    default:
        break;
    }
    
}

/*void Combat::combat(Heros heros,int action){
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