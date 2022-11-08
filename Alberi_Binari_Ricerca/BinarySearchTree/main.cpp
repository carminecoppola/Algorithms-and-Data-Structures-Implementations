
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

    /*tree.insertTree(12);
    tree.insertTree(9);
    tree.insertTree(5);
    tree.insertTree(2);
    tree.insertTree(13);
    tree.insertTree(17);
    tree.insertTree(18);
    tree.insertTree(19);
    tree.insertTree(15);*/

    tree.insertTree(13);
    tree.insertTree(12);
    tree.insertTree(16);
    tree.insertTree(10);
    tree.insertTree(11);
    tree.insertTree(14);
    tree.insertTree(17);

    cout<<endl<<"Abero preOrder: "<<endl;
    tree.preOrderVisit(tree.getRoot());
    
    cout<<endl<<endl<<"Radice: "<<tree.getRoot()->getInfo()<<endl<<endl;

    cout<<endl<<"Abero inOrder: "<<endl;
    tree.inOrderVisit(tree.getRoot());
    
    return 0;
}