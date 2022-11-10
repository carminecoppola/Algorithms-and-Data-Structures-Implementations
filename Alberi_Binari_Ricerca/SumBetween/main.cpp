/*  Progettare un algoritmo ricorsivo che dato un ABR sommi le
    chiavi comprese tra il valore m ed il valore M, con m<M
*/

#include <iostream>
#include "binarySearchTree.h"

using namespace std;

template <class Item>
Item sumBetween(binarySearchTree<int> tree , Nodo<Item> *x, int k){

    if (k == 0)
        return x->getInfo();
    else{
        return x->getInfo() + sumMinimum(tree,tree.successorTree(x),k-1);
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

    // int k = 0;
    // cout << endl << "• Inserire il numero di k nodi da sommare: " << endl;
    // cin >> k;
    // auto *min = tree.minimumTree(tree.getRoot());

    // //cout << endl << "La somma delle foglie è: "<<  sumMinimum(tree,min,k-1) << endl;


};