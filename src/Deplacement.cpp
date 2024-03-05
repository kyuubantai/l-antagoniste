#include "Deplacement.h"
#include "Monde.h"

Deplacment::deplacement(char action)  {
    int new_x=current_x;
    int new_y=current_y;
    switch (event)
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

    if (tabCase[new_x][new_y].libre) {
        current_x=new_x;current_y=new_y;
    }
}