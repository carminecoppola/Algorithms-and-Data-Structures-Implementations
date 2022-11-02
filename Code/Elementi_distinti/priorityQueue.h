#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include<iostream>
#include<vector>
#include"maxHeap.h"
using namespace std;

template<class Item>
class priorityQueue : public maxHeap<Item>{
    private:

    public:
        priorityQueue(vector<Item>);
        Item maximum();     //Restituisce il massimo
        Item minimum();
        Item extractMax();  //Rimuove e restituisce l'elemento nell'albero con priorità maggiore
        Item extractMin();
        void insertMH(Item x);  //Restituisce l'elemento nella coda
        void increasePriority(int num, Item key);    //Aumenta il valore della priorita di x al nuovo valore
        void decreasePriority(int num,Item key);
};

//Costruttore
template<class Item> priorityQueue <Item>::priorityQueue(vector<Item> albero):maxHeap<Item>(albero){}

/*  Metodo di inserimento che richiama l'insert() modificato 
    nella classe "maxHeap" a cui passiamo l'elemento da inserire
*/
template<class Item> void priorityQueue <Item>::insertMH(Item x){
    this->insert(x);

}

/*  Metodo di getter che ci permette di ritornare l'elemento
    massimo della coda.
*/

template<class Item> Item priorityQueue <Item>::maximum(){
    return this->getAlbero().at(0);
}

/*Questo metodo ci ritorna l' elemento minimo della coda, 
essendo un "minHeap" lo troveremo nella posizione 0*/

template<class Item> Item priorityQueue<Item>::minimum(){
    return this->getAlbero().at(0);
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

template<class Item> Item priorityQueue <Item>::extractMax(){

    if (this->getSize() == 0){
        return -1;
    }
    int max = maximum();

    swap(this->albero.at(0),this->albero.at(this->getSize()-1));
    this->setSize(this->getSize()-1);
    this->maxHeapify(0);

    return max;
    
}

/*Questo metodo serve per l'estrazione del numero minore presente nella coda
  Per prima coda facciamo un controllo sul size, dopodiche richiamiamo il metodo
  minimum() su una variabile min.
  Effettiamo lo swap() tra la radice e l'elemento inserito, poi settiamo il size e
  richiamaiamo il minHeapify() per ripristinare le proprietà del minHeapify(), 
  infine ritorniamo il minimo;
*/

template<class Item> Item priorityQueue<Item>::extractMin(){

    if (this->getSize() == 0){
        return -1;
    }

    int min = minimum();

    this->albero.erase(this->albero.begin());
    this->setSize(this->getSize()-1);
    this->minHeapify(0);

    return min;
   
}

/*  Questo metodo ci servirà per incrementare la priorità di un 
    elemento all'interno della coda, quindi lo spingiamo verso
    l'alto. Abbiamo un ciclo while che verificherà che la radice
    sarà minore dell' i-esimo elemento.
    Qualora lo fosse ripristinerà la proprietà del max-Heap quindi
    scambierà i due elementi. Infine riassenerà l'indice i alla
    radice. 
*/

template<class Item> void priorityQueue<Item>::increasePriority(int i, Item key){

    if (key < this->getAlbero().at(i)){
        cout<<"Invalid Data"<<endl;
        exit;
    }

    this->albero.at(i) = key;
    
    while(i > 0 && this->getAlbero().at(this->parent(i)) < this->getAlbero().at(i)){
        swap(this->albero.at(this->parent(i)),this->albero.at(i));
        i = this->parent(i);
    }

}

/*  Questo metodo ci servirà per decrementare la priorità di un 
    elemento all'interno della coda, quindi lo spingiamo verso
    il basso. Abbiamo un ciclo while che verificherà che la radice
    sarà maggiore dell' i-esimo elemento.
    Qualora lo fosse ripristinerà la proprietà del max-Heap quindi
    scambierà i due elementi. Infine riassenerà l'indice i alla
    radice. 
*/

template<class Item> void priorityQueue <Item>::decreasePriority(int num, Item key){

    if (key < this->getAlbero().at(num)){
        cout<<"Invalid Data"<<endl;
        exit;
    }

    this->albero.at(num) = key;
        
    while(num > 0 && this->getAlbero().at(this->parent(num)) > this->getAlbero().at(num))
    {
        swap(this->albero.at(this->parent(num)),this->albero.at(num));
        num = this->parent(num);
    }

}

#endif