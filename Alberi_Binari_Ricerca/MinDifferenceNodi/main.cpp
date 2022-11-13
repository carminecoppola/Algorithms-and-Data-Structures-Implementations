/*  Dato un ABR, trovare la minima differenza tra le chiavi
    di due nodi.
*/

#include <iostream>
#include<vector>
#include<limits.h>
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
Item differenzaRic(vector<Item> array, int i, int diff,int min){


    if (i == array.size()-1)
        return min; 

    if (abs(array.at(i) - array.at(i+1)) <= diff){

        diff = abs(array.at(i) - array.at(i+1));
        return differenzaRic(array,i+1,diff,i);
    }
    else{
        return differenzaRic(array,i+1,diff,min);
    }
}

int main(){

    binarySearchTree<int> tree;

    tree.insert(3);
    tree.insert(24);
    tree.insert(13);
    tree.insert(9);
    tree.insert(18);
    tree.insert(1);
    tree.insert(21);

    cout<<endl<<"• Albero In-Order: "<<endl;
    tree.inOrderVisit(tree.getRoot());
    cout<<endl;

    vector<int> array;
    arrayVisit(tree.getRoot(),&array);

    cout<<endl<<"Vector: ";
    for(auto i:array)
        cout<<i<<" ";
    cout<<endl;

    int ind = differenzaRic(array, 0, UINT16_MAX,0);
    cout << "I nodi minimi sono " << array.at(ind) << " e " << array.at(ind+1) << endl;

    return 0;
}