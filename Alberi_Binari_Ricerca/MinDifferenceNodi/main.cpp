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
};

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
};

template<class Item>
Item differenzaRic(vector<Item> array, int i, int diff){

    int min = 0;
    if (i == array.size()-1)
        return min; 
    if (abs(array.at(i) - array.at(i+1)) < diff)
        min = i;

    return differenzaRic(array,i+1,abs(array.at(i) - array.at(i+1)));
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

    int figlio = differenzaRic(array,0,UINT16_MAX);
    cout << "I nodi minimi sono " << array.at(figlio) << " e " << array.at(figlio+1) << endl;

    return 0;
}