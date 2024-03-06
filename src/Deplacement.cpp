#include "Deplacement.h"
#include "Monde.h"

Deplacement::deplacement(char action,Monde monde)  {
    int nvX=monde.getX();
    int nvY=monde.getY();
    switch (action)
    {
        case 'h':
            nvY+=1;
        case 'b':
            nvY-=1;
        case 'g':
            nvX-=1;
        case 'd':
            nvX+=1;
        
    }

    if (monde.Carte[0][0].tabCase[nvX][nvY].libre) {
        monde.setX(nvX);
        monde.setY(nvY);
    }
}