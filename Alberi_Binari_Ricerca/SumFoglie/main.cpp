/*  Progettare un algoritmo ricorsivo che dato un ABR sommi le
    chiavi di tutte le foglie
*/

#include "binarySearchTree.h"
#include<iostream>

using namespace std;

template<class Item>
Item sommaFoglie(Nodo<Item> *x){

    if (x->getLeft() == nullptr || x->getRight() == nullptr)
        return x->getInfo();
    else
        return sommaFoglie(x->getLeft())+sommaFoglie(x->getRight());
    
    
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

    cout<<endl<<"• Albero Pre-Order: "<<endl;
    tree.preOrderVisit(tree.getRoot());
    
    cout<<endl<<endl<<"  -Radice: "<<tree.getRoot()->getInfo()<<endl;

    cout<<endl<<"• Albero In-Order: "<<endl;
    tree.inOrderVisit(tree.getRoot());
    cout<<endl;

    int somma = sommaFoglie(tree.getRoot());
    cout<<endl<<"La somma delle foglie è: " <<somma<<endl;


    return 0;
}