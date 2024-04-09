#include "Combat.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;



bool est_valide = false;

Combat::Combat(){
    srand(time(NULL));
    fin = false;
    tour = MOI;
    for(int i=0; i<((rand()%3)+1);i++){
        ennemis.push_back(en);
    }
    cout<<"Il y a "<<ennemis.size()<<" ennemis"<<endl;
}

Combat::~Combat(){
    if(!ennemis.empty()) ennemis.clear();
}
Ennemi Combat::selecteurEnnemi(int pos, vector<Ennemi> ennemis){
    cout<<"sélectionne ennemi"<<endl;
    switch (pos)
    {
    case 0:
        ennemis.front();
        est_valide = true;
        cout<<"1 touché"<<endl;
        break;
    case 1:
        ennemis.at(1);
        est_valide = true;
        cout<<"2 touché"<<endl;
        break;
    case 2:
        ennemis.back();
        est_valide = true;
        cout<<"3 touché"<<endl;
        break;
    default:
        break;
    }
}

string Combat::selecteurObj(int pos,Heros h){
    cout<<"sélecteur objet"<<endl;
    switch (pos)
    {
    case 0:
        return h.inventaire[0];
        est_valide = true;
        break;
    case 1:
        return h.inventaire[1];
        est_valide = true;
        break;
    case 2:
        return h.inventaire[2];
        est_valide = true;
        break;
    case 3:
        return h.inventaire[3];
        est_valide = true;
        break;
    case 4:
        return h.inventaire[4];
        est_valide = true;
        break;
    case 5:
        return h.inventaire[5];
        est_valide = true;
        break;
    case 6:
        return h.inventaire[6];
        est_valide = true;
        break;
    case 7:
        return h.inventaire[7];
        est_valide = true;
        break;
    case 8:
        return h.inventaire[8];
        est_valide = true;
        break;
    case 9:
        return h.inventaire[9];
        est_valide = true;
        break;
    default:
        break;
    }
}

void Combat::selecteurComp(int action,vector<Ennemi>ennemis,Heros h){
    cout<<"On est dans selecteurComp"<<endl;
    Competence comp;
    Ennemi select;
    EtatComp et = MENUCOMP;
    switch(et){
        case MENUCOMP:
            cout<<"Sélecteur comp"<<endl;
            switch (action){
                case 1: //Compétence qui fait une attaque monocible
                    et = MONO;
                    break;

                case 2: // Compétence mutlicible
                    et = MULTI;
                    break;
                
                case 3: //heal
                    et = HEAL;
                    break;
                
                default:
                    break;
            }
            break;
        
    case MONO:
        cout<<"Monocible"<<endl;
        select = selecteurEnnemi(action,ennemis);
        comp.atkMono(select.stats.vie,h.stats.energie,h.stats.atkBase);
        cout<<"L'ennemi a "<<select.stats.vie<<" PV"<<endl;
        cout<<"Il vous reste "<<h.stats.energie<<" énergie"<<endl;
        est_valide = true;
        break;
    
    case MULTI:
        cout<<"Multicible"<<endl;
        for(long unsigned int i=0;i<ennemis.size();i++){
            comp.atkMulti(ennemis[i].stats.vie,h.stats.energie,h.stats.atkBase);
            cout<<"L'ennemi a "<<ennemis[i].stats.vie<<" PV"<<endl;
        }
        cout<<"Il vous reste "<<h.stats.energie<<" énergie"<<endl;
        est_valide = true;
        break;
    
    case HEAL:
        cout<<"heal"<<endl;
        comp.soin(h.stats.vie,h.stats.energie,h.stats.vieMax);
        cout<<"Vous avez "<<h.stats.vie<<" PV"<<endl;
        cout<<"Il vous reste "<<h.stats.energie<<" énergie"<<endl;
        est_valide = true;
        break;

    default:
        break;
    }
}



void Combat::menu(Heros hero, int action){
    cout<<"On utilise la fonction menu"<<endl;
    //bool garde = false;
    Ennemi select_ennemi;
    string select_obj;
    etat=MENUBASE;
    switch(etat){
        case MENUBASE:
            cout<<"Menu principal"<<endl;
            switch (action)
            {
                case 1:
                    { // Attaque basique
                    etat = SELECT;
                    select_ennemi = selecteurEnnemi(action,ennemis);
                    break;
                    }
                
                case 2: {// Garde
                    //garde = true;
                    //hero.stats.def*=1.2;
                    cout<<"garde"<<endl;
                    est_valide = true;
                    break;
                }
                case 3 : {// Compétences
                    etat = COMP;
                    break;
                }
                case 4 : {// Objets
                    etat = OBJ;
                    break;
                }
                case 0 : {// Retraite 
                    cout<<"Retraite"<<endl;
                    fin = true;
                    est_valide = true;
                    break;
                }
                
                default:
                    break;
                }
            break;
        case SELECT:
            cout<<"Attaque normale"<<endl;
            break;
        case COMP:
            cout<<"Sélectionne la comp"<<endl;
            selecteurComp(action,ennemis,hero);
            break;
        default:
            break;

    }
        
    if(etat!=MENUBASE && est_valide) etat=MENUBASE;
}

void Combat::combat(Heros heros, int action){
    if(tour == MOI){ 
        cout<<"Votre tour"<<endl;
        menu(heros,action);}
    else{
        cout<<"Tour ennemi"<<endl;
        for(long unsigned int y=0;y<ennemis.size();y++){
            heros.stats.vie -= ennemis[y].stats.atkBase;
        }
        cout<<"Il te reste "<<heros.stats.vie<<" PV"<<endl;
    }
    if(tour == MOI && est_valide) tour = ENNEMI;
    else{ 
        tour = MOI;
        est_valide = false;
    }

    for(long unsigned int i=0;i<ennemis.size();i++) {
        if(heros.stats.vie==0 || ennemis[i].stats.vie==0){
            fin=true;
            }
        }
    }

    /*if(heros.stats.vie<=0){cout<<"défaite"<<endl;}
    for(int j=0;j<ennemis.size();j++){
    if(ennemis[j].stats.vie<=0){cout<<"victoire"<<endl;}
    }*/

