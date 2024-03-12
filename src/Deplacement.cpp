#include "Deplacement.h"
#include "Monde.h"


void Deplacement::deplacement(char action,Monde monde) {
    int new_x=monde.getX();
    int new_y=monde.getY();
    switch (action)
    {
        case 'h':
            new_y+=1;
        case 'b':
            new_y-=1;
        case 'g':
            new_x-=1;
        case 'd':
            new_x+=1;
        
    }

    int carte=monde.getCarte();

    if (monde.tabCarte[carte].tabCase[new_x][new_y].libre) {
        monde.setX(new_x);
        monde.setY(new_y);
    }
}
void Deplacement::interaction(char action, Monde monde) {
}
