#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include"minHeap.h"

using namespace std;

template <class Item>
class minPriorityQueue : public minHeap <Item>{
    private:
        /* data */
    public:
        minPriorityQueue();
        void insertMH(Item x);
        Item minimum();
        Item extractMin();
        void decreasePriority(int, Item);
};

//Costruttore
template <class Item> minPriorityQueue<Item>::minPriorityQueue():minHeap<Item>(){

}

//Questo metodo richiama il metodo insert() modificato nella classe "minHeap"
template<class Item> void minPriorityQueue <Item>::insertMH(Item x){
    this->insert(x);

}

/*Questo metodo ci ritorna l' elemento minimo della coda, 
essendo un "minHeap" lo troveremo nella posizione 0*/

template<class Item> Item minPriorityQueue <Item>::minimum(){
    return this->getAlbero().at(0);
}

/*Questo metodo serve per l'estrazione del numero minore presente nella coda
  Per prima coda facciamo un controllo sul size, dopodiche richiamiamo il metodo
  minimum() su una variabile min.
  Effettiamo lo swap() tra la radice e l'elemento inserito, poi settiamo il size e
  richiamaiamo il minHeapify() per ripristinare le proprietà del minHeapify(), 
  infine ritorniamo il minimo;
*/
template<class Item> Item minPriorityQueue<Item>::extractMin(){

    if (this->getSize() == 0){
        return -1;
    }

    int min = minimum();

    this->albero.erase(this->albero.begin());
    this->setSize(this->getSize()-1);
    this->minHeapify(0);

    return min;
   
}

/*  Questo metodo ci servirà per decrementare la priorità di un 
    elemento all'interno della coda, quindi lo spingiamo verso
    il basso. Abbiamo un ciclo while che verificherà che la radice
    sarà maggiore dell' i-esimo elemento.
    Qualora lo fosse ripristinerà la proprietà del max-Heap quindi
    scambierà i due elementi. Infine riassenerà l'indice i alla
    radice. 
*/
template<class Item> void minPriorityQueue <Item>::decreasePriority(int i, Item key){

    if (key < this->getAlbero().at(i)){
        cout<<"Invalid Data"<<endl;
        exit;
    }

    this->albero.at(i) = key;
        
    while(i > 0 && this->getAlbero().at(this->parent(i)) > this->getAlbero().at(i))
    {
        swap(this->albero.at(this->parent(i)),this->albero.at(i));
        i = this->parent(i);
    }

}

#endif