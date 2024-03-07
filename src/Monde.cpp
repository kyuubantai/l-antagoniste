#include "Monde.h"

Monde::Monde(){

}


int Monde::getX(){
    return mX;
}

int Monde::getY(){
    return mY;
}

void Monde::setX(const int& nvX){
    mX=nvX;
}

void Monde::setY(const int& nvY){
    mY=nvY;
}

int Monde::getCarteX() const{
    return mCarteX;
}

int Monde::getCarteY() const {
    return mCarteY;
}