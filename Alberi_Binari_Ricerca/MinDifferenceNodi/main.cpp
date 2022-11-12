/*  Dato un ABR, trovare la minima differenza tra le chiavi
    di due nodi.
*/

#include <iostream>
#include<vector>
#include "binarySearchTree.h"
#include<limits.h>

using namespace std;

template<class Item>
void arrayVisit(Nodo<Item> *current, vector<Item> *array){

    if (current != nullptr){
        arrayVisit(current->getLeft(),array);
        cout<<array->push_back(current->getInfo())<<" ";    //Rimettiamo nell'array l'elemento attuale
        arrayVisit(current->getRight(),array);
    }
    
}

int main(){

    binarySearchTree<int> tree;
    vector<int> array;

    tree.insert(15);
    tree.insert(12);
    tree.insert(16);
    tree.insert(10);
    tree.insert(11);
    tree.insert(14);
    tree.insert(17);

    cout << endl << "• Albero Pre-Order: " << endl;
    tree.preOrderVisit(tree.getRoot());
    
    cout << endl << endl << "  -Radice: "<<tree.getRoot()->getInfo()<<endl;

    cout<<endl<<"• Albero In-Order: "<<endl;
    tree.inOrderVisit(tree.getRoot());
    cout<<endl;

    arrayVisit(tree.getRoot(),&array);
    for (int i = 0; i < array.size(); i++)
    {
        cout << i << endl;
    }

    return 0;
}