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
    cout<<endl;

    //Calcolo la radice
    cout<<endl<<"Radice: "<< tree.getRoot()->getInfo()<<endl;

    nodo<int> *n = tree.treeSearch(tree.getRoot(),12);

    cout << endl <<"Questo è il nodo ricercato tramite la treeSearch(): " << n->getInfo() <<endl;

    //MAX E MIN
    cout << endl <<"Il mimimo dell'albero è: " << tree.getMinimum(tree.getRoot())->getInfo()<< endl; 
    cout << endl <<"Il massimo dell'albero è: " << tree.getMaximum(tree.getRoot())->getInfo()<< endl; 

    //SUCCESSORE E PREDECESSORE
    cout << endl <<"Il predecessore del numero " << n->getInfo() << " è: " << tree.predecessor(n)->getInfo()<< endl;
    cout << endl <<"Il successore del numero " << n->getInfo() << " è: " << tree.successor(n)->getInfo()<< endl;

    return 0;
}