#include "Jerarquia.hpp"

using namespace std;

Jerarquia::Jerarquia(){}


Jerarquia::Jerarquia(string id, string tipo, string nombre, string fecha){
    this->id = id;
    this->tipo = tipo;
    this->nombre = nombre;
    this->fecha = fecha;
}

Jerarquia::Jerarquia(string id, string tipo, string nombre, string fecha, vector <string> alianzas){
    this->id = id;
    this->tipo = tipo;
    this->nombre = nombre;
    this->fecha = fecha;
    this->alianzas = alianzas;
}

Jerarquia::Jerarquia(string id, string tipo, string nombre, string fecha, vector <Ciudadano> ciudadanos){
    this->id = id;
    this->tipo = tipo;
    this->nombre = nombre;
    this->fecha = fecha;
    this->ciudadanos = ciudadanos;
}

string Jerarquia::getId(){
    return this->id;
}

void Jerarquia::setId(string id){
    this->id = id;
}

string Jerarquia::getTipo(){
    return this->tipo;
}

void Jerarquia::setTipo(string tipo){
    this->tipo = tipo;
}

string Jerarquia::getNombre(){
    return this->nombre;
}

void Jerarquia::setNombre(string nombre){
    this->nombre = nombre;
}

string Jerarquia::getFecha(){
    return this->fecha;
}

void Jerarquia::setFecha(string fecha){
    this->fecha = fecha;
}

vector <string> Jerarquia::getAlianzas(){
    return this->alianzas;
}

void Jerarquia::setAlianzas(vector <string> alianzas){
    this->alianzas = alianzas;
}

vector <Ciudadano> Jerarquia::getCiudadanos(){
    return this->ciudadanos;
}

void Jerarquia::setCiudadanos(vector <Ciudadano> ciudadanos){
    this->ciudadanos = ciudadanos;
}

ostream &operator<<(ostream &os, Jerarquia const &jerarquia)
{
    os << jerarquia.id << " " << jerarquia.tipo << " " << jerarquia.nombre << " " << jerarquia.fecha;
    return os;
}
