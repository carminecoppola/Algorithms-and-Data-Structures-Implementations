
/*  Progettare una classe BinarySearchTree che implementi un
    albero binario di ricerca con le seguenti funzioni 
        • SEARCH
        • MINIMUM
        • MAXIMUM
        • PREDECESSOR 
        • SUCCESSOR
        • INSERT
        • DELETE3

*/

#include <iostream>
#include"binarySearchTree.h"
#include"nodo.h"

using namespace std;

int main(){

    binarySearchTree<int> tree;

    int n,f;
    
    cout<<"Quanti nodi vuoi inserire? "<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Inserire valore "<<i+1<<" : "<<endl;
        cin>>f;
        tree.insert(f);
    }
    

    // tree.insert(13);
    // tree.insert(12);
    // tree.insert(16);
    // tree.insert(10);
    // tree.insert(11);
    // tree.insert(14);
    // tree.insert(17);

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