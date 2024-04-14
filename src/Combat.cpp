#include "Combat.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;



bool est_valide = false;
bool garde = false;

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
    case 0://Retraite
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
void Combat::selecteurEnnemi(int pos, vector<Ennemi> ennemis){
    switch (pos)
    {
    case 1:
        cout<<"1 touché"<<endl;
        ennemis[0].stats.vie -=10;
        est_valide = true;
        break;
    case 2:
        cout<<"2 touché"<<endl;
        ennemis[1].stats.vie -=10;
        est_valide = true;
        break;
    case 3:
        cout<<"3 touché"<<endl;
        ennemis[2].stats.vie -=10;
        est_valide = true;
        break;
    case 0:
        etat = MENUBASE;
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

void Combat::selecteurComp(int action,vector<Ennemi>ennemis,Heros h){
    cout<<"On est dans selecteurComp"<<endl;
    Competence comp;
    Ennemi select;
    EtatComp et = MENUCOMP;
    int choix2;
    et = saisirComp(action);
    switch(et){   
        case MONO:
            cout<<"Monocible: sélectionne ennemi"<<endl;
            cin>>choix2;
            selecteurEnnemi(choix2,ennemis);
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


void Combat::menu(Heros heros, int action){
    cout<<"MENU PRINCIPAL"<<endl;
    int choix;
    Ennemi select_ennemi;
    string select_obj;
    etat=MENUBASE;
    etat = saisirchoix(action);
        switch(etat){
            case SELECT:
                cout<<"sélectionne ennemi"<<endl;
                cin>>choix;
                selecteurEnnemi(choix,ennemis);
                cout<<"L'ennemi a "<<select_ennemi.stats.vie<<" pv"<<endl;
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

void Combat::combat(Heros heros, int action){
    fin = false;
    if(tour == MOI){ 
        cout<<"Votre tour"<<endl;
        menu(heros,action);
        cout<<est_valide<<endl;
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
    
        if(fin){
            cout<<"Fin du combat"<<endl;
        }
    

    for(long unsigned int i=0;i<ennemis.size();i++) {
        if(heros.stats.vie==0 || ennemis[i].stats.vie==0){
            fin=true;
                }
            }
    
    if(heros.stats.vie<=0){cout<<"défaite"<<endl;}
    for(long unsigned int j=0;j<ennemis.size();j++){
        if(ennemis[j].stats.vie<=0){cout<<"victoire"<<endl;}
    } 
}


    

