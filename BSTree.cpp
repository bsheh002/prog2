#include <algorithm> //included to use max function
#include "BSTree.h"
using namespace std;


BSTree::BSTree() { //constructor
    this->rootOfTree = nullptr; //root is null pointer
}
void BSTree::clearTree(Node* clearingNode){ //recursively clears the tree from node
    if (clearingNode != nullptr) {
        clearTree(clearingNode->left); //clear left subtree
        clearTree(clearingNode->right); //clear right subtree
        delete clearingNode; //delete node
    }
}
BSTree::~BSTree(){ //destructor
    clearTree(rootOfTree);
}
Node*BSTree::copyTree(Node* copyingNode) const{ //recursively copies tree from node
    if (copyingNode == nullptr) { //checks if node is null
        return nullptr;
    }

    Node* newNode = new Node(copyingNode->nodeOfWords);
    // Recursively copy left and right subtrees
    newNode->left = copyTree(copyingNode->left);
    newNode->right = copyTree(copyingNode->right);

    return newNode;
}
BSTree& BSTree::operator=(const BSTree& copyingNode){ // Assignment operator overload
    if(this!=&copyingNode){
        clearTree(rootOfTree);
        rootOfTree= copyTree(copyingNode.rootOfTree); // Copy new tree
    }
    return *this;
}

void BSTree::insert(const string &insertNode) { //inserts a node with a given string
    Node *stringNode = new Node(insertNode);
    if (rootOfTree == nullptr) {
        rootOfTree = stringNode; //new node becomes the root
        return;
    }
    Node *iterator = rootOfTree;
    while (iterator != nullptr) {
        if (insertNode < iterator->nodeOfWords) {
            if (iterator->left == nullptr) {
                iterator->left = stringNode; //inserts on the left
                iterator = nullptr; //exits
            } else {
                iterator = iterator->left; //goes through left subtree
            }
        } else if (insertNode > iterator->nodeOfWords) {
            if (iterator->left == nullptr) {
                if (iterator->right == nullptr) {
                    iterator->right = stringNode; //inserts on the right
                    iterator = nullptr; //exits
                } else {
                    iterator = iterator->right; //goes through right subtree
                }
            } else {
                iterator->counter++;
                break; //exits loop
            }
        }
    }
}
// Search for a node with the given value in the tree
    bool BSTree::search(const string &searchingNode) const {
        return search(rootOfTree, searchingNode); //recursive search
    }
    //recursive search function
    bool BSTree::search(Node *iterator, const string &searchingNodeRec) const {
        if (iterator == nullptr) {
            return false; //value isn't found
        }
        if (searchingNodeRec == iterator->nodeOfWords) {
            return true;
        } else if (searchingNodeRec < iterator->nodeOfWords) {
            return search(iterator->left, searchingNodeRec); //search left
        } else {
            return search(iterator->right, searchingNodeRec); //search right
        }
    }
// Find the node with the largest value in the tree
    string BSTree::largest() const {
        if (rootOfTree == nullptr) {
            return ""; //empty string if tree is empty
        }

        Node *iterator = rootOfTree;
        while (iterator->right != nullptr) {
            iterator = iterator->right;
        }
        return iterator->nodeOfWords; //return right node value
    }
    string BSTree::smallest() const {
        if (rootOfTree == nullptr) {
            return ""; //empty string if tree is empty
        }

        Node *iterator = rootOfTree;
        while (iterator->left != nullptr) {
            iterator = iterator->left;
        }
        return iterator->nodeOfWords; //return left node value
    }
// Calculate the height of the tree
    int BSTree::height(Node *heightOfNode) const {
        if (heightOfNode == nullptr) {
            return -1; //no height
        }
        //recursively calculates max
        return 1 + max(height(heightOfNode->left), height(heightOfNode->right));
    }
// Get a node with the given value from the tree
    Node *BSTree::get(const string &wordInInput) const {
        Node *iterator = rootOfTree;
        while (iterator != nullptr) {
            if (wordInInput == iterator->nodeOfWords) {
                return iterator; //if value matches, return node
            }
            if (wordInInput < iterator->nodeOfWords) {
                iterator = iterator->left;
            } else {
                iterator = iterator->right;
            }
        }
        return nullptr;
    }
    // Calculate the height of the node with the given value
    int BSTree::height(const string &heightOfNode) const {
        Node *nodeGetter = get(heightOfNode); //get node
        if (nodeGetter == nullptr) {
            return -1; //not found
        }
        //if leaf, height is zero, else, calculate it
        if (nodeGetter->left == nullptr && nodeGetter->right == nullptr) {
            return 0;
        }

        return height(nodeGetter); //recursive height calculation
    }
// Find the node with the largest value in the subtree
    Node *BSTree::ReturnBiggestNode(Node *iteratorRight, Node *parent) {
        if (iteratorRight == nullptr) { //checks if right subtree is null
            return parent;
        }
        return ReturnBiggestNode(iteratorRight->right, iteratorRight);
    }
// Find the node with the smallest value in the subtree
    Node *BSTree::ReturnSmallestNode(Node *iteratorLeft, Node *parentNode) {
        if (iteratorLeft == nullptr) { //checks if left subtree is null
            return parentNode;
        }
        return ReturnSmallestNode(iteratorLeft->left, iteratorLeft);
    }
//removes a node with a given string
    void BSTree::remove(const string &removeNodeRec) {
        Node *prev = nullptr;
        Node *curr = rootOfTree;
        while (curr != nullptr) {
            if (curr->nodeOfWords == removeNodeRec) {
                break;
            }
            if (removeNodeRec < curr->nodeOfWords) {
                prev = curr;
                curr = curr->left;
            } else {
                prev = curr;
                curr = curr->right;
            }
        }
//checks to see if curr is null
        if (curr == nullptr) return;
        if (curr->counter > 1) { //checks to see if counter is bigger than 1
            curr->counter--;
            return;
        }

        if (curr->left == nullptr && curr->right == nullptr) { //checks to see if empty
            if (prev == nullptr) {
                rootOfTree = nullptr; //makes tree empty
                return;
            }
            if (prev->right == curr) {
                prev->right = nullptr;
                delete curr; // deletes node
            } else if (prev->left == curr) {
                prev->left = nullptr;
                delete curr; //deletes node
            }
        } else {
            Node *successor = nullptr;
            if (curr->left) { //finds biggest node
                successor = ReturnBiggestNode(curr->left, curr);
            } else if (curr->right) { //finds smallest node
                successor = ReturnSmallestNode(curr->right, curr);
            }
            string data = successor->nodeOfWords;
            int count = successor->counter;
            successor->counter = 0;
            remove(data);
            curr->nodeOfWords = data;
            curr->counter = count;
        }
        return;
    }


    void BSTree::preOrder() const { //prints in preorder iteration
        preOrder(rootOfTree);
    }
    void BSTree::preOrder(Node *iterator) const { //prints in preorder iteration
        if (iterator != nullptr) {
            cout << iterator->nodeOfWords << "(" << iterator->counter << "), ";
            preOrder(iterator->left);
            preOrder(iterator->right);
        }
    }
    void BSTree::inOrder() const { //prints in inorder iteration
        inOrder(rootOfTree);
    }
    void BSTree::inOrder(Node *iterator) const { //prints in inorder iteration
        if (iterator != nullptr) {
            inOrder(iterator->left);
            cout << iterator->nodeOfWords << "(" << iterator->counter << "), ";
            inOrder(iterator->right);
        }
    }
    void BSTree::postOrder() const { //prints in postorder iteration
        postOrder(rootOfTree);
    }

    void BSTree::postOrder(Node *iterator) const { //prints in postorder iteration
        if (iterator != nullptr) {
            postOrder(iterator->left);
            postOrder(iterator->right);
            cout << iterator->nodeOfWords << "(" << iterator->counter << "), ";
        }
    }
