#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_H

#include<iostream>
#include<vector>
#include"binarySearchTree.h"
using namespace std;

template<class Item>
class maxPriorityQueue{

    private:
        binarySearchTree<Item> tree;

    public:

        Item maximum();     //Restituisce il massimo
        void extractMax();  //Rimuove e restituisce l'elemento nell'albero con priorità maggiore
        void insertMH(Item nodo);  //Restituisce l'elemento nella coda
        void IncreasePriority(Item num, Item key);    //Aumenta il valore della priorita di x al nuovo valore
        void printABR();
};

/*  Metodo di inserimento che richiama l'insert() modificato 
    nella classe "maxHeap" a cui passiamo l'elemento da inserire
*/
template<class Item> void maxPriorityQueue <Item>::insertMH(Item nodo){

    tree.insert(nodo);
}

/*  Metodo di getter che ci permette di ritornare l'elemento
    massimo della coda.
*/

template<class Item> Item maxPriorityQueue <Item>::maximum(){
    
    return tree.maximumTree(tree.getRoot())->getInfo();
}

/*  Questo metodo serve ad estrarre l'elemento più grande
    della radice. Il primo controllo viene fatto sul Size
    richiamando il metodo getSize() presente nella sezione 
    protected della superclasse "maxHeap".
    Impostiamo il massimo = alla funzione di getter maximum()
    che ci ritorna il primo elemento della coda, quindi la 
    radice (prima posizione).
    Dopodichè effettiamo lo scambio tra la la radice e 
    l'elemento...
    Settiamo il nuovo size e richiamaiamo il maxHeapify(),
    infine ritorniamo il massimo.

*/

template<class Item> void maxPriorityQueue <Item>::extractMax(){

    if (tree.getRoot() == nullptr)
        exit;
    
    tree.deleteTree(tree.maximumTree(tree.getRoot()));
    
}

/*  Questo metodo ci servirà per incrementare la priorità di un 
    elemento all'interno della coda, quindi lo spingiamo verso
    l'alto. Abbiamo un ciclo while che verificherà che la radice
    sarà minore dell' i-esimo elemento.
    Qualora lo fosse ripristinerà la proprietà del max-Heap quindi
    scambierà i due elementi. Infine riassenerà l'indice i alla
    radice. 
*/

template<class Item> void maxPriorityQueue<Item>::IncreasePriority(Item i, Item key){

    auto *nodo = tree.treeSearch(i,tree.getRoot());

    if (nodo->getInfo() > key || nodo == nullptr)
        exit;
    
    tree.deleteTree(nodo);
    tree.insert(key);

}

template<class Item> void maxPriorityQueue<Item>::printABR(){

    tree.inOrderVisit(tree.getRoot());
}

#endif //QUEQUE_H