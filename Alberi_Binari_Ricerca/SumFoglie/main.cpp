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

    tree.insertTreeRicors(13,nullptr,tree.getRoot());
    tree.insertTreeRicors(12,nullptr,tree.getRoot());
    tree.insertTreeRicors(16,nullptr,tree.getRoot());
    tree.insertTreeRicors(10,nullptr,tree.getRoot());
    tree.insertTreeRicors(11,nullptr,tree.getRoot());
    tree.insertTreeRicors(14,nullptr,tree.getRoot());
    tree.insertTreeRicors(17,nullptr,tree.getRoot());

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