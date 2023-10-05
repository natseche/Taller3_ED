#include "BinaryTree.hpp"

template <typename T>
bool BinaryTree<T>::addNodeAux(T const &data, BinaryNode<T> *&node)
{
    if (node == nullptr)
    {
        node = new BinaryNode<T>(data);
        return true;
    }
    else if (node->leftChild == nullptr)
    {
        return addNodeAux(data, node->leftChild);
    }
    else if (node->rightChild == nullptr)
    {
        return addNodeAux(data, node->rightChild);
    }

    // Se supone que un arbol binario no puede tener dos nodos con el mismo valor
    // por lo que si se llega a este punto, se retorna false.
    // Depende de la implementacion necesaria y el problema.
    return false;
}

template <typename T>
void BinaryTree<T>::preOrderAux(BinaryNode<T> *node, list<T> &lista) const
{
    if (node == nullptr)
    {
        cout << endl << "El nodo es nullptr";
        return;
    }

    lista.push_back(node->data);
    cout << endl << node->data;
    preOrderAux(node->leftChild, lista);
    preOrderAux(node->rightChild, lista);
}

template <typename T>
void BinaryTree<T>::inOrderAux(BinaryNode<T> *node, list<T> &lista) const
{
    if (node == nullptr)
    {
        return;
    }

    inOrderAux(node->leftChild, lista);
    lista.push_back(node->data);
    inOrderAux(node->rightChild, lista);
}

template <typename T>
void BinaryTree<T>::postOrderAux(BinaryNode<T> *node, list<T> &lista) const
{
    if (node == nullptr)
    {
        return;
    }

    postOrderAux(node->leftChild, lista);
    postOrderAux(node->rightChild, lista);
    lista.push_back(node->data);
}

template <typename T>
BinaryTree<T>::BinaryTree(T const &data)
{
    root = new BinaryNode<T>(data);
}

template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    delete root;
    root = nullptr;
}

template <typename T>
T BinaryTree<T>::getRoot() const
{
    return root->data;
}

template <typename T>
bool BinaryTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <typename T>
bool BinaryTree<T>::addNode(T const &data)
{
    if (isEmpty())
    {
        root = new BinaryNode<T>(data);
        return true;
    }

    return addNodeAux(data, root);
}

template <typename T>
list<T> BinaryTree<T>::preOrder() const
{
    // Creamos una lista vacia para almacenar los datos del arbol
    // en preorden.
    list<T> lista;

    // Llamamos a la funcion auxiliar para recorrer el arbol en preorden.
    // Recibe por referencia la lista vacia para ir agregando los datos
    // del arbol.
    preOrderAux(root, lista);

    return lista;
}

template <typename T>
list<T> BinaryTree<T>::inOrder() const
{
    list<T> lista;

    inOrderAux(root, lista);

    return lista;
}

template <typename T>
list<T> BinaryTree<T>::postOrder() const
{
    list<T> lista;

    postOrderAux(root, lista);

    return lista;
}

template<typename T>
void BinaryTree<T>::operacion1(){
    string indi;
    bool encontrado = true;
    cout << endl << "Indique el ID del Baron del cual quiere saber las tierras: " << endl;
    cin >> indi;
    encontrado = BinaryTree::buscarID(indi);  
    if (!encontrado){
        cout << endl << "El ID no fue encontrado" << endl;
    }
}

template<typename T>
bool BinaryTree<T>::buscarID(string indi){
    bool enc = false;
    BinaryNode<T>* nodo = this->raiz;
    if(nodo->id == indi){
        enc = true;
        cout << endl << "Nombre: " << nodo->nombre << endl;
        cout << endl << "Tierra 1: " << nodo->left->nombTierras << endl;
        cout << endl << "Tierra 2: " << nodo->right->nombTierras << endl;;
    }
    return enc;
}

template<typename T>
void BinaryTree<T>::operacion2(int Estrato){
    BinaryNode<T>* nodo = this->raiz;
    if(nodo->ciudadanos != nullptr){
        if(nodo->ciudadanos->estrato == Estrato){
            cout << endl << "Nombre: " << nodo->nombre << endl;
            for (Ciudadano &ciudadano : nodo->ciudadanos){
                cout << endl << "Nombre: " << nodo->nombre << endl;
                cout << endl << "Tierra asociada: " << nodo->nombTierras << endl;
            }
        }
    }
}
