/* 	Trevor Berggren
	z1906236
	CSCI 340 
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "btree.h"

// put statements in header file
template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};

template <typename T>
void BinarySearchTree<T>::Insert(const T &x)
{
    _Insert(this->root,x);
   
}

// public version that calls the private function with root
template <typename T>
bool BinarySearchTree<T>::Search(const T &x) const 
{
    return _Search(this->root,x);
}

// public version that calls the private function with root
template <typename T>
bool BinarySearchTree<T>::Remove(const T &x)
{
    if(Search(x))               // calls search to make sure it exists
    {
        _Remove(this->root,x);
        return true;
    }
 
    else
        return false;   
}

/**
 * Inserts a value
 * 
 * @param x value
 *
 * inserts a new node to the tree 
 ********************************************************************/
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T> *&root, const T &x)
{
    if(root == nullptr)                     // checks if root is null
        root = new Node<T>(x);              // if it is null makes a new node 

    else if(x < root->data)             // if adding to the left side
       _Insert(root->left,x);               // calls _Insert to add to the left 
        

    else if(x > root->data)
        _Insert(root->right,x);             // calls _Insert to add to the right
   
}

/**
 * searchs for a value
 * 
 * @param x value
 *
 * looks for a value in the tree 
 ********************************************************************/
template <typename T>
bool BinarySearchTree<T>::_Search(Node<T> *root, const T &x) const 
{
    while(root != nullptr)                  // runs while there are nodes
    {
   
    if(x < root->data)                      // check for the left side
        root = root->left;

    else if(x > root->data)                 // checks for right side
        root = root->right;

    else
        return true;
    
    }

    return false;

}

/**
 * removes a leaf
 * 
 * @param x value
 *
 * removes a leaf from the tree 
 ********************************************************************/
template <typename T>
void BinarySearchTree<T>::_Remove(Node<T> *&root, const T &x)
{
    if(root == nullptr)                 // returns if none in the tree
        return;

    if(x < root->data)                  // check for the left side
        _Remove(root->left,x);

    else if(x > root->data)             // checks for right side
        _Remove(root->right,x);

    else
    {
        if(_Leaf(root))                 // checks if value is a leaf
        {                               // deletes and sets to null;
            delete root;
            root = nullptr;
            return;
        }
    }

    
}

/**
 * Checks if a leaf 
 * 
 * @param x value
 *
 * returns true if leaf
 ********************************************************************/
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> *node) const
{
    // if left side and right are null its a leaf
    if(node->left == nullptr && node->right == nullptr)
        return true;
    
    else
        return false;

}


#endif // End of BINARYSEARCHTREE_H_