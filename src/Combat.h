#include "Combat.h"
#include <iostream>

using namespace std;

Combat::Combat(){
    nbtour = 1;
}

Combat::~Combat(){};

bool Combat::combat(){
    bool fin = false;
    while(!fin){
        (turn == Hero) ? cout<< "VOTRE TOUR"<< endl : cout << "TOUR ENNEMI"<<endl;
        if(hero.heros.comp)

    }
}