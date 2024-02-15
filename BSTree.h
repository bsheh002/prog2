#ifndef BSTREE_H
#define BSTREE_H

#include "Node.h"
#include <string>
using namespace std;

class BSTree { //creates a class of BSTs
    private:
        Node* rootOfTree;
        int height(Node *node) const;
        Node* get(const string &wordNode) const;
        bool search(Node* iterator, const string& searchingNodeRec) const;
        Node* ReturnBiggestNode(Node* iteratorRight, Node* parent);
        Node* ReturnSmallestNode(Node* iteratorLeft, Node* parentNode);
        void remove(Node* iterator, const string& removeNodeRec);
        void preOrder(Node* iterator) const;
        void inOrder(Node* iterator) const;
        void postOrder(Node* iterator) const;

    public:
    BSTree();
    ~BSTree();
    void clearTree(Node* clearingNode);
    Node*copyTree(Node* copyingNode) const;
    BSTree&operator=(const BSTree& copyingNode);
    void insert(const string &insertNode);
    bool search(const string &searchingNode) const;
    string largest() const;
    string smallest() const;
    int height(const string &heightOfNode) const;
    void remove(const string &removeNode);
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
};


#endif
