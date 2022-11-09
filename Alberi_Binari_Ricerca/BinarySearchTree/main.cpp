
/*  Progettare una classe BinarySearchTree che implementi un
    albero binario di ricerca con le seguenti funzioni 
        • SEARCH
        • MINIMUM
        • MAXIMUM
        • PREDECESSOR 
        • SUCCESSOR
        • INSERT
        • DELETE
*/

#include <iostream>
#include"binarySearchTree.h"
#include"nodo.h"

using namespace std;

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

    cout<<endl<<"  -Elemento trovato: "<<tree.treeSearch(12,tree.getRoot())->getInfo()<<endl;

    cout<<endl<<"  -Il minimo è: "<<tree.minimumTree(tree.getRoot())->getInfo()<<endl;
    cout<<endl<<"  -Il massimo è: "<<tree.maximumTree(tree.getRoot())->getInfo()<<endl;

    auto *x = tree.treeSearch(14,tree.getRoot());
    cout<<endl<<"  -Il successore del nodo "<< x->getInfo()<<" è: "<< tree.successorTree(x)->getInfo() <<endl;
    
    
    cout<<endl<<"  -Il predecessore del nodo "<< x->getInfo()<<" è: "<< tree.predecessorTree(x)->getInfo() <<endl;
    
    cout<<endl<<"  -Il nodo da cancellare è: "<< x->getInfo()<<endl;
    tree.deleteTree(x);

    cout<<endl<<"• Albero Pre-Order: "<<endl<<endl;
    tree.preOrderVisit(tree.getRoot());

    cout<<endl<<endl<<"• Albero In-Order: "<<endl<<endl;
    tree.inOrderVisit(tree.getRoot());
    cout<<endl;

    return 0;
}