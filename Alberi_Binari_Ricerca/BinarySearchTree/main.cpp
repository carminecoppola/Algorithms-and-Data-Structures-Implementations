
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

    binarySearchTree<int>* tree = new binarySearchTree<int>;

    tree->insertTree(10);
    tree->insertTree(20);
    tree->insertTree(2);
    tree->insertTree(4);
    tree->insertTree(60);
    tree->insertTree(222);
    tree->insertTree(40);
    tree->insertTree(62);


    cout<<"Albero dopo inserimento:"<<endl;
    tree->preOrderVisit(tree->getRoot());
    
    return 0;
}