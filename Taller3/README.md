# Binary tree example

Este proyecto es un ejemplo de como implementar un arbol binario en C++.

## 📶 Tech stack

- [C++ 11](https://cplusplus.com/)
- [Catch2](https://github.com/catchorg/Catch2)

## 📂 Folder structure

```ascii
.
└── BinaryTree/
    ├──.vscode/
    │   ├── launch.json
    │   ├── settings.json
    │   └── tasks.json
    ├── bin
    ├── lib/
    │   └── catch.hpp
    ├── src/
    │   ├── binary_tree/
    │   │   ├── binary_node/
    │   │   │   ├── BinaryNode.cpp
    │   │   │   └── BinaryNode.hpp
    │   │   ├── BinaryTree.cpp
    │   │   └── BinaryTree.hpp
    │   ├── person/
    │   │   ├── Person.cpp
    │   │   └── Person.hpp
    │   └── main.cpp
    └── test/
        └──traverses/
            ├── traverses_complex_types.cpp
            └──traverses_primitive_types.cpp
```

## ⚙️ Compilar

En esta seccion te explico como compilar, si utilizas [VScode](https://code.visualstudio.com/) puedes utilizar los archivos de configuracion que estan en la carpeta `.vscode` puede que tengas que hacer algunas modificaciones, debido a que depende de la maquina en la que se vaya a ejecutar, te recomiendo leer [Using GCC with MinGW
](https://code.visualstudio.com/docs/cpp/config-mingw) ,[Understanding tasks.json](https://code.visualstudio.com/docs/cpp/config-mingw#_understanding-tasksjson) y [Customize debugging with launch.json](https://code.visualstudio.com/docs/cpp/config-mingw#_customize-debugging-with-launchjson), sino tambien lo puedes hacer mediante una terminal.

**IMPORTANTE**: Si vas a utilizar [VScode](https://code.visualstudio.com/) utiliza el compilador que ellos recomiendan en su articulo [Installing the MinGW-w64 toolchain](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain), recomiendan el uso de [MSYS2](https://www.msys2.org/).

### Terminal

Para compilar el archivo main desde la carpeta raiz del proyecto:

```bash
    g++ -g src/main.cpp src/person/Person.cpp -o bin/main
```

Para compilar los archivos de testing desde la carpeta raiz del proyecto:

- Tests de datos complejos (Persona)

```bash
    g++ -g test/traverses/traverses_complex_types.cpp src/person/Person.cpp -o bin/traverses_complex_types_test
```

- Tests de datos primitivos (Integer, Char, String, Float, etc...)

```bash
    g++ -g test/traverses/traverses_primitive_types.cpp -o bin/traverses_primitive_types
```

_La compilacion de los tests puede tardar bastante, se paciente._

## 👟 Ejecucion de los programas

Para ejecutar el archivo main desde la carpeta raiz del proyecto:

```bash
    ./bin/main.exe
```

Para compilar los archivos de testing desde la carpeta raiz del proyecto:

- Tests de datos complejos (Persona)

```bash
    ./bin/traverses_complex_types_test.exe -s
```

- Tests de datos primitivos (Integer, Char, String, Float, etc...)

```bash
    ./bin/traverses_primitive_types.exe -s
```

## 📅 Recordatorios claves

- **compilacion de una clase template**: Cuando tengas que compilar una clase que utiliza programacion generica (Plantillas o templates), debes poner al final del archivo `.h`, `.hpp` o `.hxx`, el archivo donde esta implementado los metodos, como el en siguiente ejemplo:

```cpp
#if !defined(BINARY_NODE_HPP)
#define BINARY_NODE_HPP

#include <ostream>

using namespace std;

template <typename T>
class BinaryNode
{

protected:
    /* Attributes*/

public:
    /* Constructor and Destructor */

    /* Getters and Setters */

    /* Operators */

    /* Methods */

    /* Friends */
};

#include "BinaryNode.cpp"

#endif // BINARY_NODE_HPP
```

Y en el archivo `.cpp` o `.cxx` debe estar el encabezado:

```cpp
#include "BinaryNode.hpp"

template <typename T>
BinaryNode<T>::BinaryNode(T data)
{
    this->data = data;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

/*etc..*/
```

Asi mismo para compilar por consola omite la insercion de estos a los argumentos.

```bash
    g++ -g src/main.cpp src/person/Person.cpp -o bin/main
```

El archivo main utiliza las clases `BinaryTree` y `BinaryNode` que son templates no son necesarias añadirlas al compilar, pero si no fueran templates, es necesario.

- **Orden de los operadores <,>,<=,>=**: Siempre lo que esta al lado izquierdo cuando hagas la sobrecarga de los operadores se considera como `this` es decir hace referencia al objeto en si mismo:

```cpp
// BinaryNode.cpp

template <typename T>
bool BinaryNode<T>::operator<(const BinaryNode<T> &otherBinaryNode) const
{
    return data < otherBinaryNode.data;
}

template <typename T>
bool BinaryNode<T>::operator>(const BinaryNode &otherBinaryNode) const
{
    return data > otherBinaryNode.data;
}

```

- **Sintaxis de la sobrecarga de <<**: Al sobrecarga este operador tiene una sintaxis especial debido a que esta requiere que se utilice el keyword `friend` para el correcto funcionamiento:

```cpp
// Person.hpp

#include <ostream>

class Person
{
    //etc
    friend ostream &operator<<(ostream &os, Person const &person);
}

// Person.cpp

ostream &operator<<(ostream &os, Person const &person)
{
    os << person.name << " " << person.lastName << " " << person.age;
    return os;
}
```

Para clases en las cuales se utiliza templates su sintaxis tambien cambia:

```cpp
// BinaryNode.hpp

#include <ostream>


template <typename T>
class BinaryNode
{
    // ...
    template <typename U>
    friend ostream &operator<<(ostream &os, const BinaryNode<U> &binaryNode);
    // ...
};

#include "BinaryNode.cpp"

// BinaryNode.cpp

#include "BinaryNode.hpp"

// ...

template <typename U>
ostream &operator<<(ostream &os, const BinaryNode<U> &binaryNode)
{
    os << "data: " << binaryNode.data;
    return os;
}

// ...
```

**Keyword friend**: Se utiliza para otorgar acceso especial a una clase o función externa a una clase, permitiéndole acceder a miembros privados de esa clase (No es necesario utilizar Getters y Setters desde la clase amiga para acceder a atributos o a funciones private o protected).

```cpp
template <typename T>
class BinaryNode
{
    // ...
     /* Friends */
    template <typename U>
    friend class BinaryTree;
    // ...
};
```

Debido a que ambas clases utilizan templates, es necesario cambiar la letra que representa el template de la clase amiga, esto debido a que el compilador no puede identificar a cual template hacemos referencia.

De lo contrario solo se alladiria la clase sin el template.

**Keyword explicit**: Se utiliza en la declaración de un constructor para indicar que dicho constructor no debe ser utilizado de manera implícita para realizar conversiones de tipos. Esto significa que el constructor no será utilizado automáticamente por el compilador para convertir un tipo en otro en situaciones donde la conversión no sea evidente y segura.

```cpp
// BinaryNode.hpp

template <typename T>
class BinaryNode
{
    // ...
    explicit BinaryNode(T data);
    // ...
};

#include "BinaryNode.cpp"

// BinaryNode.cpp
#include "BinaryNode.hpp"

template <typename T>
BinaryNode<T>::BinaryNode(T data)
{
    this->data = data;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}
```

## Algunos otros metodos de un arbol binario

La anterior implementacion es algo muy basico y sencillo, pero existen otros metodos que se pueden implementar en un arbol binario, como por ejemplo:

```cpp
 remove(const T &data);
 clear();
 find(const T &data) const;
 height() const;
 smallest();
 largest();
 etc...
```

La mayoria de los anteriores metodos requieren del uso de la recursion, por ello es importante entender como funciona la recursion, te recomiendo leer [Recursion](https://www.geeksforgeeks.org/recursion/). Ademas de utilizar funciones auxiliares para poder implementarlos.

## 📚 Recursos

- [Binary Tree](https://www.geeksforgeeks.org/what-is-binary-tree/?ref=gcse)
- [Binary Tree Traversals](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/)
- [Simulation](https://www.cs.usfca.edu/~galles/visualization/BST.html)
