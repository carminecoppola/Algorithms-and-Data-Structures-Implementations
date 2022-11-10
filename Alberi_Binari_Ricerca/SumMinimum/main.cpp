/* Progettare un algoritmo ricorsivo che dato un ABR sommi le k
chiavi più piccole */

#include<iostream>
#include"binarySearchTree.h"

using namespace std;

template<class Item>
Item sumMinimum(Nodo<Item> *x){


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
};