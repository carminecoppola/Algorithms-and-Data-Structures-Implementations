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

    cout<<endl<<"• Ricerca nell'albero "<<endl;
    tree.treeSearch(tree.getRoot(),14);

    return 0;
}