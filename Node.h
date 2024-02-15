#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

struct Node { //creates a struct for node
    string nodeOfWords;
    int counter;
    Node* left;
    Node* right;
    Node(const string& nodeOfWords);
};


#endif
