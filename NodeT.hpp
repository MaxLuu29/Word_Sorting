#ifndef NodeT_hpp
#define NodeT_hpp
#include "wordInfo.hpp"
#include <string>
using namespace std;

class NodeT {
    friend class AVLTree;
    friend class AC;
    wordInfo *w;
    int height;
    NodeT *left;
    NodeT *right;
    NodeT *parent;
public:
    NodeT(string x);
    ~NodeT();
    void printNode();
};

#endif /* NodeT_hpp */
