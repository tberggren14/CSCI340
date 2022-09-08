/* 	Trevor Berggren
	z1906236
	CSCI 340 
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#ifndef H_BTREE
#define H_BTREE

#include "node.h"
#include <cstddef>

template <typename T>
class BinaryTree;

template <typename T> class BinaryTree{

public:
    BinaryTree() = default;                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns _getHeight of tree
    void         Inorder(void (*)(const T&));          // _Inorder traversal of tree

protected:
    Node<T> *root = nullptr;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
    
};


// public version that calls the private function with root
template <typename T>
unsigned BinaryTree<T>::getSize() const
{
    return _getSize(root);
}

// public version that calls the private function with root
template <typename T>
unsigned BinaryTree<T>::getHeight() const 
{
    return _getHeight(root);
}


// public version that calls the private function with root
template <typename T>
void BinaryTree<T>::Inorder(void (*print)(const T&x)) 
{
    _Inorder(root,print);
}


/**
 * Returns the tree size.
 *
 * @return The number of elements stored in the tree.
 ********************************************************************/
template <typename T>
unsigned BinaryTree<T>:: _getSize(Node<T> *root) const
{
  
   if(root == nullptr)                  // checks if root is null 
   {
    return 0;                           // returns 0 if root is null
   }

    // calls _getSize to get the size of tree
    return(_getSize(root->left) + 1 + _getSize(root->right));

}

/**
 * Returns the height.
 * 
 * @param root is a pointer to a tree node
 *
 * @return The height of the tree
 * recursive private function
 ********************************************************************/
template <typename T>
unsigned BinaryTree<T>:: _getHeight(Node<T> *root) const
{
    size_t left_height;
    size_t right_height;

    if(root == nullptr)
    {
        return 0;               // if root is null _getHeight is 0
    }

    else 
    {
        left_height = _getHeight(root->left);      // assigns
        right_height = _getHeight(root->right);

        if(left_height > right_height)
             return left_height + 1;        // if left is bigger

        else                                // if left is less than right
            return right_height + 1;
    }

}


/**
 * Prints inorder
 * 
 * @param root is a pointer to a tree node
 * @param void print 
 *
 * recursive private function
 ********************************************************************/
template <typename T>
void BinaryTree<T>:: _Inorder(Node<T> *root, void (*print)(const T&x))
{
    if(root != nullptr)                // checks for null
    {
        _Inorder(root->left,print);           // prints _Inorder of going left and right
        print(root->data);
        _Inorder(root->right,print);
    }

}

#endif // End of H_BTREE