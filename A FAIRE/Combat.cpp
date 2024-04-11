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

Etat Combat::saisirchoix(int choice){
    Etat e;
    switch (choice)
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
    case 0://Retraite
        e = RETREAT;
        break;
    
    default:
        break;
    }
    return e;

}

EtatComp Combat::saisirComp(int choice){
    EtatComp Ec;
    switch(choice){
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
Ennemi Combat::selecteurEnnemi(int pos, vector<Ennemi> ennemis){
    switch (pos)
    {
    case 0:
        return ennemis[0];
        est_valide = true;
        cout<<"1 touché"<<endl;
        break;
    case 1:
        return ennemis[1];
        est_valide = true;
        cout<<"2 touché"<<endl;
        break;
    case 2:
        return ennemis[2];
        est_valide = true;
        cout<<"3 touché"<<endl;
        break;
    default:
        etat = MENUBASE;
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
        etat = MENUBASE;
        break;
    }
}

void Combat::selecteurComp(int action,vector<Ennemi>ennemis,Heros h){
    cout<<"On est dans selecteurComp"<<endl;
    Competence comp;
    Ennemi select;
    EtatComp et = MENUCOMP;
    et = saisirComp(action);
    switch(et){   
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
        etat = MENUBASE;
        break;
    }
}


void Combat::menu(Heros hero, int action){
    cout<<"MENU PRINCIPAL"<<endl;
    //bool garde = false;
    int choix;
    Ennemi select_ennemi;
    string select_obj;
    etat=MENUBASE;
    etat = saisirchoix(action);
        switch(etat){
            case MENUBASE:
                cout<<"Menu principal :"<<endl;
                break;
            case SELECT:
                cout<<"sélectionne ennemi"<<endl;
                cin>>choix;
                select_ennemi = selecteurEnnemi(choix,ennemis);
                select_ennemi.stats.vie -=10;
                cout<<"L'ennemi a "<<select_ennemi.stats.vie<<" pv"<<endl;
                break;
            case COMP:
                cout<<"Sélectionne la comp"<<endl;
                cin>>choix;
                selecteurComp(choix,ennemis,hero);
                break;
            case GUARD:
                cout<<"Garde"<<endl;
                break;
            case OBJ:
                break;
            case RETREAT:
                cout<<"Retraite"<<endl;
                fin = true;
                break;
            default:
                break;
        }
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
    if(tour == MOI && fin){
        cout<<"Fin du combat"<<endl;
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

