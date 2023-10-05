#ifndef JERARQUIA_HPP
#define JERARQUIA_HPP

#include <iostream>
#include <vector>
#include "Ciudadano.hpp"

using namespace std;

class Jerarquia{
    private:
        string id;
        string tipo;
        string nombre;
        string fecha;
        vector <string> alianzas;
        vector <Ciudadano> ciudadanos;
    public:
        Jerarquia();
        Jerarquia(string,string,string,string);
        Jerarquia(string,string,string,string,vector<string>);
        Jerarquia(string,string,string,string,vector<Ciudadano>);

        string getId();
        void setId(string);
        string getTipo();
        void setTipo(string);
        string getNombre();
        void setNombre(string);
        string getFecha();
        void setFecha(string);
        vector<string> getAlianzas();
        void setAlianzas(vector<string>);
        vector<Ciudadano> getCiudadanos();
        void setCiudadanos(vector<Ciudadano>);

        friend ostream &operator<<(ostream &os, Jerarquia const &jerarquia);

};

#endif // JERARQUIA_HPP