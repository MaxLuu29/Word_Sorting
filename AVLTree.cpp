#include "AVLTree.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;
AVLTree::AVLTree() {
    root = NULL;
    
}
// This method should return true if a new node is inserted and
// false if the data x is already in the tree
bool AVLTree:: insertit(string x) {
    if (root == NULL) {
        root = new NodeT(x);
        size++;
        return true;
    } else {
        NodeT* n = root;
        while (n != NULL) {
            if (x < n->w->word) {
                if (n->left == NULL) {
                    NodeT* tmp = new NodeT(x);
                    n->left = tmp;
                    tmp->parent = n;
                    size++;
                    adjustHeights(tmp);
                    return true;
                } else {
                    n = n->left;
                }
            } else if (x > n->w->word) {
                if (n->right == NULL) {
                    NodeT* tmp = new NodeT(x);
                    n->right = tmp;
                    tmp->parent = n;
                    size++;
                    adjustHeights(tmp);
                    return true;
                } else {
                    n = n->right;
                }
            } else if (x == n->w->word){
                n->w->ct++;
                return false;
            }
        }
    }
    return false;
}

// the adjustHeights method updates the heights of every ancestor of the node n.
void AVLTree::adjustHeights(NodeT *n) {
    if (n == NULL) {
        return;
    } else {
        if (n->left == NULL && n->right == NULL) {
            n->height = 1;
        } else if (n->left == NULL && n->right != NULL) {
            n->height = 1 + n->right->height;
        } else if (n->left != NULL && n->right == NULL) {
            n->height = 1 + n->left->height;
        } else {
            n->height = max(n->left->height, n->right->height) + 1;
        }
        
        //check for balance and if necessary rotate accordingly
        if (findBalance(n) >= 2) {
            if (findBalance(n->left) >= 1) {
//                cout<< n->data << " must rotate right (" << findBalance(n) << ")" <<endl;
                rotateRight(n);
            } else if (findBalance(n->left) <= -1) {
//                cout<< n->left->data << " child, rotating left" <<endl;
                rotateLeft(n->left);
            }
        } else if (findBalance(n) <= -2) {
            if (findBalance(n->right) <= -1) {
//                cout<< n->data << " must rotate left (" << findBalance(n) << ")" <<endl;
                rotateLeft(n);
            } else if (findBalance(n->right) >= 1) {
//                cout<< n->right->data << " child, rotating right" <<endl;
                rotateRight(n->right);
            }
        }
        adjustHeights(n->parent);
    }
}

void AVLTree::printTreeIO() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        printTreeIO(root);
    }
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is
// traversed in order
void AVLTree::printTreeIO(NodeT *n) {
    if (n == NULL) {
        return;
    } else {
        printTreeIO(n->left);
        n->printNode();
        printTreeIO(n->right);
    }
}

void AVLTree::printTreePre() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        printTreePre(root);
    }
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void AVLTree::printTreePre(NodeT *n) {
    if (n == NULL) {
        return;
    } else {
        n->printNode();
        printTreePre(n->left);
        printTreePre(n->right);
    }
}

void AVLTree::printTreePost() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        printTreePost(root);
        cout << endl;
    }
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void AVLTree::printTreePost(NodeT *n) {
    if (n == NULL) {
        return;
    } else {
        printTreePost(n->left);
        printTreePost(n->right);
        n->printNode();
    }
}

void AVLTree::myPrint() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        myPrint(root);
        cout << endl;
    }
}
void AVLTree::myPrint(NodeT *n) {
    if (n == NULL) {
        return;
    }
    else {
        myPrint(n->left);
//        cout << n->data.length()-1;
        if (mine) {
            cout <<".";
            mine = false;
        }
        myPrint(n->right);
    }
}

// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.
NodeT *AVLTree::find(string x) {
    int counter = 0;
    if (root == NULL) {
        cout<< "The tree is empty" <<endl;
        return NULL;
    } else {
        NodeT *n = root;
        while (n != NULL) {
            if (n->w->word == x) {
                counter++;
                cout<<counter<<": ";
                n->printNode();
                return n;
            } else if (x < n->w->word) {
                n = n->left;
                counter++;
            } else {
                n = n->right;
                counter++;
            }
        }
    }
    cout<<x<<" not found"<<endl;
    return NULL;
}

NodeT* AVLTree::rotateRight(NodeT* n) {
    NodeT* tmp = n->left;
    if (n == root) {
        if (tmp->right != NULL) {
            tmp->right->parent = n;
            n->left = tmp->right;
            tmp->right = n;
            root = tmp;
            n->parent = tmp;
            tmp->parent = NULL;
        } else {
            tmp->right = n;
            n->left = NULL;
            n->parent = tmp;
            tmp->parent = NULL;
            root = tmp;
        }
    } else {
        if (tmp->right != NULL) {
            tmp->right->parent = n;
            n->left = tmp->right;
        } else if (tmp->right == NULL) {
            n->left = NULL;
        }
        
        if (n->parent->right == n) {
            n->parent->right = tmp;
            tmp->parent = n->parent;
            n->parent = tmp;
            tmp->right = n;
        } else if (n->parent->left == n) {
            n->parent->left = tmp;
            tmp->parent = n->parent;
            n->parent = tmp;
            tmp->right = n;
        }
    }
    adjustHeights(n);
    return tmp;
}

NodeT* AVLTree::rotateLeft(NodeT* n) {
    NodeT* tmp = n->right;
    if (n == root) {
        if (tmp->left != NULL) {
            tmp->left->parent = n;
            n->right = tmp->left;
            tmp->left = n;
            root = tmp;
            tmp->parent = NULL;
            n->parent = tmp;
        } else {
            tmp->left = n;
            n->right = NULL;
            root = tmp;
            tmp->parent = NULL;
            n->parent = tmp;
        }
    } else {
        if (tmp->left != NULL) {
            n->right = tmp->left;
            tmp->left->parent = n;
        } else if (tmp->left == NULL) {
            n->right = NULL;
        }
        
        if (n->parent->right == n) {
            n->parent->right = tmp;
            tmp->parent = n->parent;
            n->parent = tmp;
            tmp->left = n;
        } else if (n->parent->left == n) {
            n->parent->left = tmp;
            tmp->parent = n->parent;
            n->parent = tmp;
            tmp->left = n;
        }
    }
    adjustHeights(n);
    return tmp;
}

int AVLTree::findBalance(NodeT* n) {
    if (n->left == NULL && n->right == NULL) {
        return 0;
    } else if (n->right == NULL && n->left != NULL) {
        return n->left->height;
    } else if (n->left == NULL && n->right != NULL) {
        return 0 - n->right->height;
    }
    return n->left->height - n->right->height;
}
