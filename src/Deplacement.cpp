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
        std::cout<<new_x<<new_y<<std::endl;
        monde.setX(new_x);
        monde.setY(new_y);
    }
    if (monde.tabCarte[carteX].tabCase[new_x][new_y].sortie) {
        std::cout<<"Sortie"<<std::endl;
        switch (action)
        {
            case 'h':
                new_x=6;
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
void Deplacement::interaction(char action, Monde &monde) {
}
