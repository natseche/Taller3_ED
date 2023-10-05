#ifndef CIUDADANO_HPP
#define CIUDADANO_HPP

#include <iostream>

using namespace std;

class Ciudadano{
    private:
        string nombre;
        int estrato;
        string localidad;
    public:
        Ciudadano(string,int,string);

        string getNombre();
        int getEstrato();
        string getLocalidad();
};

#endif // CIUDADANO_HPP