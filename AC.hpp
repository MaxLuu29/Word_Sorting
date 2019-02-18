#ifndef AC_hpp
#define AC_hpp

#include "AVLTree.hpp"
#include "wordInfo.hpp"
#include "Sorting.hpp"
#include <iostream>
using namespace std;
class AC {
    bool verbose;
    AVLTree *tree;
    string fn;
    wordInfo **wordarr;
    wordInfo **predictions;
    int currSize;
    string curr;
    Sorting sorts;
public:
    AC(string f1,bool isverbose=false);
    void readFile();
    void convertToArray();
    void convertToArray(NodeT *n);
    void printArr();
    string stripSpace(string s);
    void ui();
    void getPredictions();
    int findBeg();
    int findEnd();
};

#endif /* AC_hpp */
