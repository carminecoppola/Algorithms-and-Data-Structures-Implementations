/*  Progettare un algoritmo ricorsivo che dato un ABR sommi le k
    chiavi più piccole.
*/

#include <iostream>
#include "binarySearchTree.h"

using namespace std;

template <class Item>
Item sumMinimum(Nodo<Item> *x, int k){

    if (k == 0)
        return x->getInfo();
    else{
        return ;
    }

};

int main(){

    binarySearchTree<int> tree;

    tree.insert(13);
    tree.insert(12);
    tree.insert(16);
    tree.insert(10);
    tree.insert(11);
    tree.insert(14);
    tree.insert(17);

    cout << endl << "• Albero Pre-Order: " << endl;
    tree.preOrderVisit(tree.getRoot());
    
    cout << endl << endl << "  -Radice: "<<tree.getRoot()->getInfo()<<endl;

    cout<<endl<<"• Albero In-Order: "<<endl;
    tree.inOrderVisit(tree.getRoot());
    cout<<endl;

    int k = 3;

    int somma = sumMinimum(tree.successorTree(tree.minimumTree(tree.getRoot())),k);

    cout << endl << "La somma delle foglie è: " << somma << endl;


};