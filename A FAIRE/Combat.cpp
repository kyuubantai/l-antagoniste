#include "Ennemi.h"
#include "Combat.h"
#include <iostream>

using namespace std;

void Combat::combat(Heros heros){
    bool fin=false;
    Ennemi ennemi;
    int n;
    while(!fin){
        if(tour == MOI){
            cout <<"Ton tour"<<endl;
            cin >> n;
            ennemi.stats.setVie(ennemi.stats.getVie()-10);
        }
        else{
            cout <<"Ennemi"<<endl;
            heros.stats.setVie(heros.stats.getVie()-10);
        }

        if(heros.stats.getVie()==0 || ennemi.stats.getVie()==0){
            fin=true;
        }

        if (tour == MOI)
		    tour = ENNEMI;
	    else
		    tour = MOI;
    }
    if(heros.stats.getVie()<=0){cout<<"défaite"<<endl;}
    if(ennemi.stats.getVie()<=0){cout<<"victoire"<<endl;}
}