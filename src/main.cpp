#include <iostream>
#include <fstream>
#include <list>
#include "binary_tree/BinaryTree.hpp"
#include "Jerarquia.hpp"
#include "Ciudadano.hpp"

using namespace std;

int menu();
vector <string> separar(string,char);

int main(int argc, char const *argv[]){

    int numero;
    bool primeraVez = true;
    string leer, token;

    fstream archivo;

    BinaryTree <Jerarquia> arbol;

    list <Jerarquia> imprimir;

    do
    {
        numero = menu();
        switch (numero)
        {
            case 1:
                archivo.open("jerarquia.txt");
                if(!archivo)
                    cout << endl << "No se pudo abrir el archivo" << endl;
                else{
                    getline(archivo, leer);
                    while(leer != "FIN"){
                        if(leer != "#"){
                            string id = leer;
                            getline(archivo, leer);
                            string tipo = leer;
                            getline(archivo, leer);
                            string nombre = leer;
                            getline(archivo, leer);
                            string fecha = leer;

                            if(primeraVez){
                                Jerarquia raiz = Jerarquia(id, tipo, nombre, fecha);
                                arbol = BinaryTree <Jerarquia> (raiz);
                                primeraVez = false;
                            }

                            getline(archivo, leer);
                            if(leer != "#" && tipo != "Tierra"){
                                vector <string> alianzas = separar(leer, ',');
                                Jerarquia nodo = Jerarquia(id, tipo, nombre, fecha, alianzas);
                                arbol.addNode(nodo);
                                getline(archivo, leer);
                            } 
                            if(leer != "#" && tipo == "Tierra"){
                                vector <string> ciudadanos = separar(leer, '%');
                                vector <Ciudadano> listaCiudadanos;
                                for(int i=0; i<ciudadanos.size(); i++){
                                    vector <string> datos = separar(ciudadanos[i], ',');
                                    Ciudadano c = Ciudadano(datos[0], stoi(datos[1]), datos[2]);
                                    listaCiudadanos.push_back(c);
                                }
                                Jerarquia nodo = Jerarquia(id, tipo, nombre, fecha, listaCiudadanos);
                                arbol.addNode(nodo);
                                getline(archivo, leer);
                            }
                            getline(archivo, leer);
                        }
                    }
                    cout << endl << "Datos cargados correctamente" << endl;
                }
                break;
            case 2:
                cout << endl << arbol.getRoot() << endl;
                imprimir = arbol.preOrder();
                cout << endl << ":D";
                /*for (Jerarquia& jerarquia : imprimir) {
                    cout << "ID: " << jerarquia.getId() << endl;
                    cout << "Tipo: " << jerarquia.getTipo() << endl;
                    cout << "Nombre: " << jerarquia.getNombre() << endl;
                    cout << "Fecha: " << jerarquia.getFecha() << endl;

                    // Si hay alianzas, imprímelas
                    if (!jerarquia.getAlianzas().empty()) {
                        cout << "Alianzas:";
                        for (const string& alianza : jerarquia.getAlianzas()) {
                            cout << " " << alianza;
                        }
                        cout << endl;
                    }

                    // Si hay ciudadanos, imprímelos
                    if (!jerarquia.getCiudadanos().empty()) {
                        cout << "Ciudadanos:" << endl;
                        for (Ciudadano& ciudadano : jerarquia.getCiudadanos()) {
                            cout << "  Nombre: " << ciudadano.getNombre() << endl;
                            cout << "  Estrato: " << ciudadano.getEstrato() << endl;
                            cout << "  Localidad: " << ciudadano.getLocalidad() << endl;
                            // Imprime otros atributos de Ciudadano si los hay
                        }
                    }

                    cout << endl;
                }*/
                break;
            case 3:
                arbol.operacion1();
                break;
            case 4:
                arbol.operacion2(0);
                break;
            case 5:
                break;
            case 6:
                cout << endl << "Chao";
                break;
            default:
                cout << endl << "Opcion invalida";
                break;
        }

    } while (numero != 6); 

    return 0;
}

BinaryTree <Jerarquia> cargarDatos(){
    BinaryTree <Jerarquia> arbol;
    fstream archivo;
    string leer, token;
    bool primeraVez = true;
    archivo.open("jerarquia.txt");
    if(!archivo)
        cout << endl << "No se pudo abrir el archivo" << endl;
    else{
        getline(archivo, leer);
        cout << endl << "id rey: " << leer << endl;
        while(leer != "FIN"){
            if(leer != "#"){
                string id = leer;
                getline(archivo, leer);
                cout << endl << "tipo: " << leer << endl;
                string tipo = leer;
                getline(archivo, leer);
                cout << endl << "nombre: " << leer << endl;
                string nombre = leer;
                getline(archivo, leer);
                cout << endl << "fecha: " << leer << endl;
                string fecha = leer;

                if(primeraVez){
                    Jerarquia raiz = Jerarquia(id, tipo, nombre, fecha);
                    arbol = BinaryTree <Jerarquia> (raiz);
                    primeraVez = false;
                }

                getline(archivo, leer);
                if(leer != "#" && tipo != "Tierra"){
                    vector <string> alianzas = separar(leer, ',');
                    Jerarquia nodo = Jerarquia(id, tipo, nombre, fecha, alianzas);
                    arbol.addNode(nodo);
                    getline(archivo, leer);
                    cout << endl << leer << endl;
                } 
                if(leer != "#" && tipo == "Tierra"){
                    vector <string> ciudadanos = separar(leer, '%');
                    vector <Ciudadano> listaCiudadanos;
                    for(int i=0; i<ciudadanos.size(); i++){
                        vector <string> datos = separar(ciudadanos[i], ',');
                        Ciudadano c = Ciudadano(datos[0], stoi(datos[1]), datos[2]);
                        listaCiudadanos.push_back(c);
                        cout << endl << datos[0] << " | " << datos[1] << " | " << datos[2];
                    }
                    Jerarquia nodo = Jerarquia(id, tipo, nombre, fecha, listaCiudadanos);
                    arbol.addNode(nodo);
                    getline(archivo, leer);
                    cout << endl << "#: " << leer << endl;
                }
                getline(archivo, leer);
                cout << endl << "fin o nuevo id: " << leer << endl;
            }
        }
    }
    cout << endl << "Preparandose para el return...";
    return arbol;
}

int menu()
{
    int numero;

    cout << endl << "---------- MENU ----------";
    cout << endl << "1. Cargar datos";
    cout << endl << "2. Ver datos";
    cout << endl << "3. Operacion 1";
    cout << endl << "4. Operacion 2";
    cout << endl << "5. printTree";
    cout << endl << "6. Salir" << endl;
    cin >> numero;

    return numero;
}

vector<string> separar(string cadena, char separador)
{
    int posInicial = 0;
    int posEncontrada = 0;
    string separado;
    vector<string> resultado;

    while(posEncontrada >= 0)
    {
        posEncontrada = cadena.find(separador, posInicial);
        separado = cadena.substr(posInicial, posEncontrada - posInicial);
        posInicial = posEncontrada + 1;
        resultado.push_back(separado);
    }

    return resultado;
}