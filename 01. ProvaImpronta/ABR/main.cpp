/*Implementare un ABR con tutti i metodi*/

#include <iostream>
#include"BinaryTree.h"

using namespace std;

int main(){

    BinaryTree<int> tree;

    tree.insert(13);
    tree.insert(12);
    tree.insert(16);
    tree.insert(10);
    tree.insert(11);
    tree.insert(14);
    tree.insert(17);

    cout<<endl<<"• Albero In-Order: "<<endl;
    tree.visitInOrder(tree.getRoot());

    //Calcolo la radice
    cout<<endl<<"Radice: "<< tree.getRoot()->getInfo()<<endl;

    //Massimo e minimo
    cout<<endl<<endl<<"L'elemento mimimo è: "<< tree.getMinimum(tree.getRoot())->getInfo()<<endl;
    cout<<endl<<endl<<"L'elemento Massimo è: "<< tree.getMaximum(tree.getRoot())->getInfo()<<endl;

    //Nodo ricercato con TREESEARCH
    Nodo<int> *nodo = tree.treeSearch(tree.getRoot(),12);

    //Successore
    cout<<endl<<"Successore di " <<nodo->getInfo()<< " : " <<tree.successor(nodo)->getInfo()<<endl;
    //Predecessore
    cout<<endl<<"Predecessore di " <<nodo->getInfo()<< " : " <<tree.predecessor(nodo)->getInfo()<<endl<<endl;

    return 0;
}