#include "Combat.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;



bool est_valide = false;
bool garde = false;

Combat::Combat(){
    fin = false;
    tour = MOI;
    srand(time(NULL));
    for(int i=0; i<((rand()%3)+1);i++){
        ennemis.push_back(en);
    }
}

Combat::Combat(Ennemi ennemi){
    ennemis.push_back(ennemi);
}

Combat::~Combat(){
    if(!ennemis.empty()) ennemis.clear();
}

Etat Combat::saisirchoix(int choix){
    Etat e;
    switch (choix)
    {
    case 1:
        e = SELECT;
        break;
    case 2: 
        e = GUARD;
        break;
    case 3:
        e = COMP;
        break;
    case 4:
        e = OBJ;
        break;
    case 5://Retraite
        e = RETREAT;
        break;
    
    default:
        break;
    }
    return e;

}

EtatComp Combat::saisirComp(int choix){
    EtatComp Ec;
    switch(choix){
        case 1:
            Ec = MONO;
            break;
        
        case 2:
            Ec = MULTI;
            break;
        
        case 3:
            Ec = HEAL;
            break;
        
        case 0:
            etat = MENUBASE;
            break;
        default:
            break;
    }
    return Ec;
}
void Combat::selecteurEnnemi(int pos, vector<Ennemi> &ennemis, Heros &h){
    Competence comp;
    switch (pos)
    {
    case 1:
        cout<<"1 touché"<<endl;
        if(etat == COMP){
            comp.atkMono(ennemis[0].stats.vie,h.stats.energie,h.stats.atkBase);
            cout<<"L'ennemi 1 a "<<ennemis[0].stats.vie<<" pv"<<endl;
        }
        else{
        ennemis[0].stats.vie -=10;
        cout<<"L'ennemi 1 a "<<ennemis[0].stats.vie<<" pv"<<endl;
        }
        est_valide = true;
        break;
    case 2:
        if(pos>ennemis.size()){
            cout<<"Choississez un autre ennemi";
        }
        else{
            cout<<"2 touché"<<endl;
            if(etat == COMP){
                comp.atkMono(ennemis[1].stats.vie,h.stats.energie,h.stats.atkBase);
                cout<<"L'ennemi 2 a "<<ennemis[1].stats.vie<<" pv"<<endl;
            }
            else{
            ennemis[1].stats.vie -=10;
            cout<<"L'ennemi 2 a "<<ennemis[1].stats.vie<<" pv"<<endl;
            }
            est_valide = true;
            break;
        }
        break;
    case 3:
       if(pos>ennemis.size()){
            cout<<"Choississez un autre ennemi";
        }
        else{
            cout<<"2 touché"<<endl;
            if(etat == COMP){
                comp.atkMono(ennemis[2].stats.vie,h.stats.energie,h.stats.atkBase);
                cout<<"L'ennemi 3 a "<<ennemis[2].stats.vie<<" pv"<<endl;
            }
            else{
            ennemis[2].stats.vie -=10;
            cout<<"L'ennemi 3 a "<<ennemis[2].stats.vie<<" pv"<<endl;
            }
            est_valide = true;
            break;
        }
        break;
    case 0:
        etat = MENUBASE;
        break;
    default:
            break;
    }
}

string Combat::selecteurObj(int pos,Heros &h){
    cout<<"sélecteur objet"<<endl;
    switch (pos)
    {
        case 0:
            etat = MENUBASE;
            break;
        case 1:
            return h.inventaire[0];
            est_valide = true;
            break;
        case 2:
            return h.inventaire[1];
            est_valide = true;
            break;
        case 3:
            return h.inventaire[2];
            est_valide = true;
            break;
        case 4:
            return h.inventaire[3];
            est_valide = true;
            break;
        case 5:
            return h.inventaire[4];
            est_valide = true;
            break;
        case 6:
            return h.inventaire[5];
            est_valide = true;
            break;
        case 7:
            return h.inventaire[6];
            est_valide = true;
            break;
        case 8:
            return h.inventaire[7];
            est_valide = true;
            break;
        case 9:
            return h.inventaire[8];
            est_valide = true;
            break;
        case 10:
            return h.inventaire[9];
            est_valide = true;
            break;
        default:
            return h.inventaire[0];
            break;
    }
}

void Combat::selecteurComp(int action,vector<Ennemi>&ennemis,Heros &h){
    cout<<"On est dans selecteurComp"<<endl;
    Competence comp;
    EtatComp et = MENUCOMP;
    int choix2;
    et = saisirComp(action);
    switch(et){   
        case MONO:
            if(h.stats.energie>30){
                cout<<"Monocible: sélectionne ennemi"<<endl;
                cin>>choix2;
                selecteurEnnemi(choix2,ennemis,h);
                cout<<"Il vous reste "<<h.stats.energie<<" énergie"<<endl;
                est_valide = true;
                break;
            }
            else{
                cout<<"Vous n'avez pas assez d'énergie"<<endl;
                break;
            }
    
    case MULTI:
        if(h.stats.energie>60){
            cout<<"Multicible"<<endl;
            for(long unsigned int i=0;i<ennemis.size();i++){
                comp.atkMulti(ennemis[i].stats.vie,h.stats.energie,h.stats.atkBase);
                cout<<"L'ennemi a "<<ennemis[i].stats.vie<<" PV"<<endl;
            }
            cout<<"Il vous reste "<<h.stats.energie<<" énergie"<<endl;
            est_valide = true;
            break;
        }
        else{
            cout<<"Vous n'avez pas assez d'énergie"<<endl;
            break;
        }
    
    case HEAL:
        if(h.stats.energie>50){
            cout<<"heal"<<endl;
            comp.soin(h.stats.vie,h.stats.energie,h.stats.vieMax);
            cout<<"Vous avez "<<h.stats.vie<<" PV"<<endl;
            cout<<"Il vous reste "<<h.stats.energie<<" énergie"<<endl;
            est_valide = true;
            break;
        }
        else{
            cout<<"Vous n'avez pas assez d'énergie"<<endl;
            break;
        }

    default:
        etat = MENUBASE;
        break;
    }
}


void Combat::menu(Heros &heros, int action){
    cout<<"MENU PRINCIPAL"<<endl;
    int choix;
    string select_obj;
    etat=MENUBASE;
    etat = saisirchoix(action);
        switch(etat){
            case SELECT:
                cout<<"sélectionne ennemi"<<endl;
                cin>>choix;
                selecteurEnnemi(choix,ennemis,heros);
                break;
            case COMP:
                cout<<"Sélectionne la comp"<<endl;
                cin>>choix;
                selecteurComp(choix,ennemis,heros);
                break;
            case GUARD:
                cout<<"Garde"<<endl;
                heros.stats.def= heros.stats.def*1.5;
                garde = true;
                est_valide = true;
                break;
            case OBJ:
                cin>>choix;
                 select_obj = selecteurObj(choix,heros);
                break;
            case RETREAT:
                cout<<"Retraite"<<endl;
                fin = true;
                break;
            default:
                break;
        }
}

void Combat::combat(Heros &heros, int action){
    cout<<"Il y a "<<ennemis.size()<<" ennemis"<<endl;
    for(long unsigned int j=0;j<ennemis.size();j++){
            cout<<"Ennemi "<<j<<" : "<<ennemis[j].stats.vie<<endl;
    }
    if(tour == MOI){ 
        cout<<"Votre tour"<<endl;
        menu(heros,action);
        cout<<fin<<endl;
        }
    else{
        cout<<"Tour ennemi"<<endl;
        for(long unsigned int y=0;y<ennemis.size();y++){
            if(garde) heros.stats.vie -= ennemis[y].stats.atkBase*0.75;
            else heros.stats.vie -= ennemis[y].stats.atkBase;
        }
        cout<<"Il te reste "<<heros.stats.vie<<" PV"<<endl;
    }
    
    if(tour == MOI && est_valide) tour = ENNEMI;
    else{ 
        tour = MOI;
        est_valide = false;
    }
    if(heros.stats.vie<=0)fin=true;

    for(long unsigned int i=0;i<ennemis.size();i++) {
        if(ennemis[i].stats.vie<=0)fin=true;
    }
    if(fin && heros.stats.vie>0){ //cas où on fait une retraite
            cout<<"Fin du combat"<<endl;
            exit(0);
    }

    //peut-être inutile à mettre ici
    if(fin && heros.stats.vie<=0){// cas où l'héros perd
        cout<<"défaite"<<endl;
        //exit(0);
    }
    else{// cas où l'héros gagne
        for(long unsigned int j=0;j<ennemis.size();j++){
            if(fin && ennemis[j].stats.vie<=0){
            cout<<"victoire"<<endl;
                exit(0);
            }
        }        
    }   
}   


    

