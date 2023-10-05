#if !defined(BINARY_TREE_HPP)
#define BINARY_TREE_HPP

#include <list>

#include "binary_node/BinaryNode.hpp"

using namespace std;

template <typename T>
class BinaryTree
{
protected:
    BinaryNode<T> *root;

private:
    bool addNodeAux(T const &data, BinaryNode<T> *&node);
    void preOrderAux(BinaryNode<T> *node, list<T> &list) const;
    void inOrderAux(BinaryNode<T> *node, list<T> &list) const;
    void postOrderAux(BinaryNode<T> *node, list<T> &list) const;

public:
    /* Constructor and Destructor */
    explicit BinaryTree(T const &data);
    BinaryTree();
    ~BinaryTree();

    /* Getters and Setters */
    T getRoot() const;

    // No tiene sentido implementar un setter para el nodo raíz, ya que
    // no se deberia poder cambiar el nodo raíz de un árbol binario.
    // void setRoot(BinaryNode<T> *root);

    bool isEmpty() const;

    bool addNode(T const &data);

    void operacion1();
    bool buscarID(string);
    void operacion2(int);

    list<T> preOrder() const;
    list<T> inOrder() const;
    list<T> postOrder() const;
};

#include "BinaryTree.cpp"

#endif // BINARY_TREE_HPP
