#include "Deplacement.h"
#include "Monde.h"
#include <iostream>

int Deplacement::getPnj() {
    return num_pnj;
}

void Deplacement::setPnj(const int& pnj) {
    num_pnj=pnj;
}

int Deplacement::getDialogue() {
    return num_dialogue;
}

void Deplacement::setDialogue(const int& num_dial) {
    num_dialogue=num_dial;
}

void Deplacement::interaction() {
    int pos_x=monde.getX();
    int pos_y=monde.getY();
    int carteX=monde.getCarte();
    int newx=pos_x;
    int newy=pos_y;
    int pos_s;
    for (int i=-1;i<2;i=i+2) {    
        if ( (monde.tabCarte[carteX].tabCase[newx=pos_x+i][newy=pos_y].pnj) || (monde.tabCarte[carteX].tabCase[newx=pos_x][newy=pos_y+i].pnj) ) {
            pos_s=newx+newy*100;
            switch(carteX) 
            {
                case 1 : if (pos_s==5) { // pos_x=5,pos_y=0 -> 5;
                    num_pnj=11;
                    if (num_dialogue==1000) {num_dialogue=0;}
                    else {num_dialogue++;}
                    break; 
                    } else if (pos_s==704) {
                    num_pnj=12;
                    if (num_dialogue==1000) {num_dialogue=0;}
                    else {num_dialogue++;}
                    }
                break;

                case 3 :  if (pos_s==1) {
                    num_pnj=31;
                    if (num_dialogue==1000) {num_dialogue=0;}
                    else {num_dialogue++;}
                    break; 
                    } else if (pos_s==204) {
                    num_pnj=32;
                    if (num_dialogue==1000) {num_dialogue=0;}
                    else {num_dialogue++;}
                    }

                break;

                case 5 : if (pos_s==701) { // pos_x=1,pos_y=7 -> 701;
                    num_pnj=51;
                    if (num_dialogue==1000) {num_dialogue=0;}
                    else {num_dialogue++;}
                    }
                break; 

                case 7 :  if (pos_s==406) {
                    num_pnj=71;
                    if (num_dialogue==1000) {num_dialogue=0;}
                    else {num_dialogue++;}
                    break; 
                    } else if (pos_s==806) {
                    num_pnj=72;
                    if (num_dialogue==1000) {num_dialogue=0;}
                    else {num_dialogue++;}
                    }

                break;
            }
        }
    }
    for (int i=-1;i<2;i=i+2) {
        if ( (monde.tabCarte[carteX].tabCase[newx=pos_x+i][newy=pos_y].coffre) || (monde.tabCarte[carteX].tabCase[newx=pos_x][newy=pos_y+i].coffre) ) {
            //ouverture d'un coffre
            pos_s=newx+newy*100; 
            switch(carteX) {
                case 8 : if (pos_s==104) {
                    std::cout<<"Vous avez obtenu une Potion";
                }
                break;
                case 9 : if (pos_s==203) {
                    std::cout<<"Vous avez obtenu une Potion";
                }
                break;
                case 11 : if (pos_s==1005) {    
                    std::cout<<"Vous avez obtenu une Potion";
                }
                break;
            }
        }
    }
    
    for (int i=-1;i<2;i=i+2) {
        if ( (monde.tabCarte[carteX].tabCase[newx=pos_x+i][newy=pos_y].ennemi) ||  (monde.tabCarte[carteX].tabCase[newx=pos_x][newy=pos_y+i].ennemi) ){
            //Lancé combat avec ennemi (Personnage)
            pos_s=newx+newy*100;
        }
    }

}

void Deplacement::deplace(char action) {
    int new_x=monde.getX();
    int new_y=monde.getY();
    if (num_dialogue==1000) {
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
