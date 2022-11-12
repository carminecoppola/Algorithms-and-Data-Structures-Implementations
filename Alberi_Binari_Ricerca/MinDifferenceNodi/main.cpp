/*  Dato un ABR, trovare la minima differenza tra le chiavi
    di due nodi.
*/

#include <iostream>
#include<vector>
#include "binarySearchTree.h"

using namespace std;

template<class Item>
void arrayVisit(Nodo<Item> *current, vector<Item> *array){

    if (current != nullptr){
        arrayVisit(current->getLeft(),array);
        array->push_back(current->getInfo());    //Rimettiamo nell'array l'elemento attuale
        arrayVisit(current->getRight(),array);
    }
}

template<class Item>
Item differenza(vector<Item> array){

    Item indice = 0;
    Item diff = abs(array.at(0) - array.at(1));

    for (int i = 1; i < array.size()-1; i++){
        if (abs(array.at(i) - array.at(i+1)) < diff){
            return i;
        }
    } 
    return 0;
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
    int prova = differenza(array);

    cout << "I nodi minimi sono " << array.at(prova) << " e " << array.at(prova+1) << endl; 

    return 0;
}