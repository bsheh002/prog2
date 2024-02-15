#include <iostream>
#include <limits>
#include "BSTree.h"

using namespace std;

void printOrders(BSTree *tree) { //prints the orders of the BST
    cout << "Preorder = ";
    tree->preOrder();
    cout << "Inorder = ";
    tree->inOrder();
    cout << "Postorder = ";
    tree->postOrder();
}

int menu() {
    int choice = 0;
    cout << endl << "Enter menu choice: ";
    cout << endl;
    cout
            << "1. Insert" << endl
            << "2. Remove" << endl
            << "3. Print" << endl
            << "4. Search" << endl
            << "5. Smallest" << endl
            << "6. Largest" << endl
            << "7. Height" << endl
            << "8. Quit" << endl;
    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

int main() {

    BSTree tree;

    int choice = menu();

    string entry;

    while (choice != 8) { //checks to see if user is quitting
        if (choice == 1) { //checks to see if choice is 1
            cout << "Enter string to insert: ";
            string data;
            getline(cin, data);
            tree.insert(data);
            cout << endl;
        } else if (choice == 2) { //checks to see if choice is 2
            cout << "Enter string to remove: ";
            string data;
            getline(cin, data);
            tree.remove(data);
            cout << endl;
        } else if (choice == 3) { //checks to see if choice is 3
            cout << "Preorder = ";
            tree.preOrder();
            cout << endl;

            cout << "Inorder = ";
            tree.inOrder();
            cout << endl;

            cout << "Postorder = ";
            tree.postOrder();
            cout << endl;
        } else if (choice == 4) { //checks to see if choice is 4
            cout << "Enter string to search for: ";
            string data;
            getline(cin, data);
            cout << endl;
            bool res = tree.search(data);
            cout << (res ? "Found" : "Not Found") << endl;
        } else if (choice == 5) { //checks to see if choice is 5
            cout << "Smallest: " << tree.smallest() << endl;
        } else if (choice == 6) { //checks to see if choice is 6
            cout << "Largest: " << tree.largest() << endl;
        } else if (choice == 7) { //checks to see if choice is 7
            cout << "Enter string: ";
            string data;
            getline(cin, data);
            cout << endl;
            cout << "Height of subtree rooted at " << data << ": " << tree.height(data) << endl;
        }

        choice = menu();
    }
    return 0;
}
