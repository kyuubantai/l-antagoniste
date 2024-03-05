#include "Deplacement.h"
#include "Monde.h"

Deplacment::deplacement(char event)  {
    int new_x,new_y;
    switch (event)
    {
        case 'h':
            new_y=current_y+1;
        case 'b':
            new_y=current_y-1;
        case 'g':
            new_y=current_x-1;
        case 'd':
            new_y=current_x+1;
        
    }

    if (tabCase[x][y].libre) {
        tabCase[x][y].libre = False;
    }
}