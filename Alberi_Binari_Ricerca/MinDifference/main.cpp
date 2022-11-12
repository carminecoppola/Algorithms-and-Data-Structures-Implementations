/*  Dato un ABR, trovare la coppia di nodi padre-figlio 
    con la minima differenza tra le chiavi.
*/

#include <iostream>
#include "binarySearchTree.h"

using namespace std;
template<class Item>
int differenza(Nodo<Item> *k){

    binarySearchTree<int> *tree;

    if (!k || !k->getParent())
        return ;
    else
        //return tree->treeSearch(k->getInfo() - k->getParent()->getInfo());       
}

template<class Item>
Nodo<Item> *min(Nodo<Item> *A,Nodo<Item> *B,Nodo<Item> *C){

    Nodo<Item> *min_nodo;

    if (differenza(A) < differenza(B))
        min_nodo = A;
    else
        min_nodo = B;
    
    if (differenza(C) < differenza(min_nodo))
        min_nodo = C;

    return min_nodo;
    
}


template<class Item>
Nodo<Item> *min_diff(Nodo<Item> *n){

    int nodo1, nodo2;

    if (n == nullptr)       //Controllo se sono foglia
        return n->getInfo();       
    else{
        nodo1 = min_diff(n->getLeft());
        nodo2 = min_diff(n->getRight());
    }
    //return ;


}

int main(){

    return 0;
}