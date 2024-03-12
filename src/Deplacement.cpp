#include "Deplacement.h"
#include "Monde.h"
#include <iostream>

void Deplacement::deplacement(char action,Monde &monde) {
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
        std::cout<<new_x<<new_y;
        monde.setX(new_x);
        monde.setY(new_y);
    }
}
void Deplacement::interaction(char action, Monde &monde) {
}
