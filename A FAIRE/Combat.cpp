#include "Ennemi.h"
#include "Combat.h"
#include <iostream>

using namespace std;

void Combat::menuPersoBase(Heros heros){
    int choix
    
}

void Combat::combat(Heros heros,int action){
    bool fin=false;
    int menu;
    char n;
    Ennemi ennemi;
    while(!fin){
        if(tour == MOI){
            switch (action){
                case 1:
                    enn
                    break;
                case 2:
                    break;
    }
        }
        else{
            cout <<"Ennemi"<<endl;
            heros.stats.setVie(heros.stats.getVie()-10);
        }


        if (tour == MOI) tour = ENNEMI;
	    else tour = MOI;
        
        if(heros.stats.getVie()==0 || ennemi.stats.getVie()==0){
            fin=true;
        }
    }
    if(heros.stats.getVie()<=0){cout<<"défaite"<<endl;}
    if(ennemi.stats.getVie()<=0){cout<<"victoire"<<endl;}
}