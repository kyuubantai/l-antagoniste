#include "Deplacement.h"
#include "Monde.h"
#include <iostream>

int Deplacement::getPnj() {
    int pos_x=monde.getX();
    int pos_y=monde.getY();
    int carteX=monde.getCarte();
    for (int i=-1;i<2;i=i+2) {    
        if (monde.tabCarte[carteX].tabCase[pos_x+i][pos_y].pnj || monde.tabCarte[carteX].tabCase[pos_x][pos_y+i].pnj) {
            int pos_s=pos_x+i*100+pos_y;
            switch(carteX) 
            {
                case 0 : if (pos_s==703) {
                    num_pnj=0;
                    num_dialogue=0;
                    break; 
                    } else if (pos_s==504) {
                    num_pnj=1;
                    num_dialogue=0;
                    break; 
                }
                break;
                case 1 : 
                    num_pnj=2;
                    num_dialogue=0;
                break;
            }
        }
    }
    return num_pnj;
}

void Deplacement::setPnj(const int& pnj) {
    num_pnj=pnj;
}

int Deplacement::getDialogue() {
    if (num_dialogue != -1) {
        num_dialogue+=1;
    }   
    return num_dialogue;
}

void Deplacement::setDialogue(const int& num_dial) {
    num_dialogue=num_dial;
}

void Deplacement::interaction() {
    int pos_x=monde.getX();
    int pos_y=monde.getY();
    int carteX=monde.getCarte();
    getPnj();

    for (int i=-1;i<2;i=i+2) {
        if (monde.tabCarte[carteX].tabCase[pos_x+i][pos_y].ennemi) {
            //Lancé combat avec ennemi (Personnage)
        }
    }
    
    for (int i=-1;i<2;i=i+2) {
        if (monde.tabCarte[carteX].tabCase[pos_x+i][pos_y].coffre) {

        }
    }


    for (int i=-1;i<2;i=i+2) {
        if (monde.tabCarte[carteX].tabCase[pos_x][pos_y+i].ennemi) {

        }
    }


    for (int i=-1;i<2;i=i+2) {
        if (monde.tabCarte[carteX].tabCase[pos_x][pos_y+i].coffre) {

        }
    }
}

void Deplacement::deplace(char action) {
    int new_x=monde.getX();
    int new_y=monde.getY();
    switch (action)
    {
        case 'h':
            new_x=new_x-1;
            break;
        case 'b':
            new_x+=1;
            break;
        case 'g':
            new_y=new_y-1;
            break;
        case 'd':
            new_y+=1;
            break;
    }


    int carteX=monde.getCarte();
    if (monde.tabCarte[carteX].tabCase[new_x][new_y].libre) {
        monde.setX(new_x);
        monde.setY(new_y);
    }

    if (monde.tabCarte[carteX].tabCase[new_x][new_y].sortie) {
        switch (action)
        {
            case 'h':
                new_x=5;
                monde.setX(new_x);
                monde.setCarte(carteX-4);
                break;
            case 'b':
                new_x=1;
                monde.setX(new_x);
                monde.setCarte(carteX+4);
                break;
            case 'g':
                new_y=10;
                monde.setY(new_y);
                monde.setCarte(carteX-1);
                break;
            case 'd':
                new_y=1;
                monde.setY(new_y);
                monde.setCarte(carteX+1);
                break;
        }
    }
}
