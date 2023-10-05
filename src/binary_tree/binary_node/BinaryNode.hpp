#if !defined(BINARY_NODE_HPP)
#define BINARY_NODE_HPP

#include <ostream>

using namespace std;

template <typename T>
class BinaryNode
{

protected:
    T data;
    BinaryNode<T> *leftChild;
    BinaryNode<T> *rightChild;

public:
    /* Constructor and Destructor */
    explicit BinaryNode(T data);    
    BinaryNode(T data, BinaryNode<T> *left, BinaryNode<T> *right);
    ~BinaryNode();

    /* Getters and Setters */
    T getData() const;
    void setData(T data);

    BinaryNode<T> *getLeft() const;
    void setLeft(BinaryNode<T> *left);

    BinaryNode<T> *getRight() const;
    void setRight(BinaryNode<T> *right);

    /* Operators */
    bool operator==(const BinaryNode &otherBinaryNode) const;

    bool operator!=(const BinaryNode &otherBinaryNode) const;

    bool operator<(const BinaryNode &otherBinaryNode) const;

    bool operator>(const BinaryNode &rhs) const;

    template <typename U>
    friend ostream &operator<<(ostream &os, const BinaryNode<U> &binaryNode);

    /* Methods */
    bool isLeaf() const;

    /* Friends */
    template <typename U>
    friend class BinaryTree;
};

#include "BinaryNode.cpp"

#endif // BINARY_NODE_HPP
