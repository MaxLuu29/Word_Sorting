#ifndef wordInfo_hpp
#define wordInfo_hpp
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class wordInfo {
    friend class NodeT;
    friend class AVLTree;
    friend class Sorting;
    friend class AC;
    string word;
    int ct;
public:
    wordInfo(string w, int x);
    wordInfo(string w);
    wordInfo();
    void printWord();
};

#endif /* wordInfo_hpp */
