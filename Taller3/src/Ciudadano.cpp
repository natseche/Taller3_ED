#include "Ciudadano.hpp"

using namespace std;

Ciudadano::Ciudadano(string nombre, int estrato, string localidad){
    this->nombre = nombre;
    this->estrato = estrato;
    this->localidad = localidad;
}

string Ciudadano::getNombre(){
    return this->nombre;
}

int Ciudadano::getEstrato(){
    return this->estrato;
}

string Ciudadano::getLocalidad(){
    return this->localidad;
}