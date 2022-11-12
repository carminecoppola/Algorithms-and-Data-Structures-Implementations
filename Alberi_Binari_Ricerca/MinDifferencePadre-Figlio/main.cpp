/*  Dato un ABR, trovare la coppia di nodi padre-figlio 
    con la minima differenza tra le chiavi.
*/

#include <iostream>
#include "binarySearchTree.h"
#include<limits.h>

using namespace std;

template<class Item>
int differenza(Nodo<Item> *k){

    if (!k || !k->getParent())
        return UINT16_MAX;    //+infinito
    else
        return abs(k->getInfo() - k->getParent()->getInfo());     //ABS = Valore Assoluto
}

/* Questa funzione ci servirà a effettuare controlli tra la differenza trovata
   a SX e quella trovata a DX. */
template<class Item>
Nodo<Item> *min(Nodo<Item> *A,Nodo<Item> *B,Nodo<Item> *C){

    Nodo<Item> *min_nodo;

    if (differenza(A) <= differenza(B))
        min_nodo = A;
    else
        min_nodo = B;
    
    if (differenza(C) <= differenza(min_nodo))
        min_nodo = C;

    return min_nodo; 
}


/*  Questa funzione ci permetterà nel caso in cui non si è una foglia
    di calcolarci la minima differenza prima a SX e poi a DX, e
    richiameremo la funzione min() su questi due risultati.     */
template<class Item>
Nodo<Item> *min_diff(Nodo<Item> *n){

    Nodo<Item> *nodo1;
    Nodo<Item> *nodo2;

    if (n == nullptr)       //Controllo se sono foglia
        return n;       
    else{
        nodo1 = min_diff(n->getLeft());
        nodo2 = min_diff(n->getRight());
    }
    return min(nodo1,nodo2,n);
}

int main(){

    binarySearchTree<int> tree;

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

    int minimaDiff = min_diff(tree.getRoot())->getInfo();
    cout << endl << "  -La minima differenza è tra "<< minimaDiff << " e suo padre " << min_diff(tree.getRoot())->getParent()->getInfo() << endl <<endl;

    return 0;
}