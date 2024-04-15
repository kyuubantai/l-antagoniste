#include "Combat.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;





Combat::Combat(){
    est_valide = false;
    garde = false;
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
        e=MENUBASE;
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
void Combat::selecteurEnnemi(long unsigned int pos, vector<Ennemi> &ennemis){
    Competence comp;
    switch (pos)
    {
    case 1:
        if(etat == COMP){
            comp.atkMono(ennemis[0].stats.vie,heros.stats.energie,heros.stats.atkBase);
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
            if(etat == COMP){
                comp.atkMono(ennemis[1].stats.vie,heros.stats.energie,heros.stats.atkBase);
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
            if(etat == COMP){
                comp.atkMono(ennemis[2].stats.vie,heros.stats.energie,heros.stats.atkBase);
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
        if(etat== COMP){
            et = MENUCOMP;
           cout<<"1 : Attaque monocible"<<endl;
           cout<<"2 : Attaque multicible"<<endl;
           cout<<"3 : soin"<<endl;
           break;
        }
        etat = MENUBASE;
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"1 : Attaque"<<endl;
        cout<<"2 : Garde"<<endl;
        cout<<"3 : Compétences"<<endl;
        cout<<"4 : Objets"<<endl;
        cout<<"5 : Retraite"<<endl;
        break;
    default:
            break;
    }
}

int Combat::selecteurObj(int pos){
    switch (pos)
    {
        case 0:
            etat = MENUBASE;
            return heros.inventaire[0];
            break;
        case 1:
            return heros.inventaire[0];
            est_valide = true;
            break;
        case 2:
            return heros.inventaire[1];
            est_valide = true;
            break;
        case 3:
            return heros.inventaire[2];
            est_valide = true;
            break;
        case 4:
            return heros.inventaire[3];
            est_valide = true;
            break;
        case 5:
            return heros.inventaire[4];
            est_valide = true;
            break;
        case 6:
            return heros.inventaire[5];
            est_valide = true;
            break;
        case 7:
            return heros.inventaire[6];
            est_valide = true;
            break;
        case 8:
            return heros.inventaire[7];
            est_valide = true;
            break;
        case 9:
            return heros.inventaire[8];
            est_valide = true;
            break;
        case 10:
            return heros.inventaire[9];
            est_valide = true;
            break;
        default:
            return heros.inventaire[0];
            break;
    }
}

void Combat::selecteurComp(int action,vector<Ennemi>&ennemis){
    Competence comp;
    EtatComp et = MENUCOMP;
    int choix2;
    et = saisirComp(action);
    switch(et){  
        case MONO:
            if(heros.stats.energie>30){
                cout<<"Monocible: Sélectionnez un ennemi"<<endl;
                cin>>choix2;
                selecteurEnnemi(choix2,ennemis);
                cout<<"Il vous reste "<<heros.stats.energie<<" énergie"<<endl;
                est_valide = true;
                break;
            }
            else{
                cout<<"Vous n'avez pas assez d'énergie"<<endl;
                break;
            }
    
        case MULTI:
            if(heros.stats.energie>60){
                cout<<"Multicible"<<endl;
                for(long unsigned int i=0;i<ennemis.size();i++){
                    comp.atkMulti(ennemis[i].stats.vie,heros.stats.energie,heros.stats.atkBase);
                    cout<<"L'ennemi a "<<ennemis[i].stats.vie<<" PV"<<endl;
                }
                cout<<"Il vous reste "<<heros.stats.energie<<" énergie"<<endl;
                est_valide = true;
                break;
            }
            else{
                cout<<"Vous n'avez pas assez d'énergie"<<endl;
                break;
            }
    
        case HEAL:
            if(heros.stats.energie>50){
                cout<<"heal"<<endl;
                comp.soin(heros.stats.vie,heros.stats.energie,heros.stats.vieMax);
                cout<<"Vous avez "<<heros.stats.vie<<" PV"<<endl;
                cout<<"Il vous reste "<<heros.stats.energie<<" énergie"<<endl;
                est_valide = true;
                break;
            }
            else{
                cout<<"Vous n'avez pas assez d'énergie"<<endl;
                break;
            }

    default:
        etat = MENUBASE;
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"1 : Attaque"<<endl;
        cout<<"2 : Garde"<<endl;
        cout<<"3 : Compétences"<<endl;
        cout<<"4 : Objets"<<endl;
        cout<<"5 : Retraite"<<endl;
        break;
    }
}


void Combat::menu(int action){
    int choix;
    string select_obj;
    etat=MENUBASE;
    etat = saisirchoix(action);
        switch(etat){
            case MENUBASE:
                cout<<"MENU PRINCIPAL"<<endl;
                cout<<"1 : Attaque"<<endl;
                cout<<"2 : Garde"<<endl;
                cout<<"3 : Compétences"<<endl;
                cout<<"4 : Objets"<<endl;
                cout<<"5 : Retraite"<<endl;
                break;
            case SELECT:
                cout<<"Séletionnez un ennemi :"<<endl;
                cin>>choix;
                selecteurEnnemi(choix,ennemis);
                break;
            case COMP:
                cout<<"Sélectionne la compétence :"<<endl;
                cin>>choix;
                selecteurComp(choix,ennemis);
                break;
            case GUARD:
                cout<<"Garde"<<endl;
                heros.stats.def= heros.stats.def*1.5;
                garde = true;
                est_valide = true;
                break;
            case OBJ:
                cout<<"Sélectionnez un objet :"<<endl;
                cin>>choix;
                select_obj = selecteurObj(choix);
                break;
            case RETREAT:
                cout<<"Retraite"<<endl;
                fin = true;
                break;
            default:
                break;
        }
}

void Combat::combat(int action){
    int total;
    cout<<"Il y a "<<ennemis.size()<<" ennemis"<<endl;
    for(long unsigned int j=0;j<ennemis.size();j++){
            cout<<"Ennemi "<<j+1<<" : "<<ennemis[j].stats.vie<<endl;
    }
    if(tour == MOI){ 
        cout<<"Votre tour"<<endl;
        menu(action);
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


    for(long unsigned int i=0;i<ennemis.size();i++) {
        total = total+ennemis[i].stats.vie;
        if(heros.stats.vie<=0 || total<=0)fin=true;
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

void Combat::initInventory() {
    for (int i=0;i<10;i++) {
        heros.inventaire[i]=0;
    }
}

void Combat::setInventory(const int& objet){
    for (int i=0;i<10;i++) {
        if (heros.inventaire[i]==0) {
            heros.inventaire[i]=objet;
            std::cout<<"Potion mise dans l'inventaire"<<endl;
        }
    }
}
    

