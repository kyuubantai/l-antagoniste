#ifndef __DEPLACEMENT__H
#define __DEPLACEMENT__H

#include "Monde.h"

class Deplacement {
    private:
        Monde monde;
        int current_x;
        int current_y;
    public:
        void deplacement(char event);
        void interaction(char event);
};


#endif