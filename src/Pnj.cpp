#include "Pnj.h"
#include <iostream>

using namespace std;

void Pnj::conversation(int& num_dial){
    if (num_dial==nb_dial-1) {
            num_dial=0;
        }
        num_dial++;
}
