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
        void insertMH(Item x);  //Restituisce l'elemento nella coda
        void IncreasePriority(int num, Item key);    //Aumenta il valore della priorita di x al nuovo valore
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

/*  Questo metodo ci servirà per incrementare la priorità di un 
    elemento all'interno della coda, quindi lo spingiamo verso
    l'alto. Abbiamo un ciclo while che verificherà che la radice
    sarà minore dell' i-esimo elemento.
    Qualora lo fosse ripristinerà la proprietà del max-Heap quindi
    scambierà i due elementi. Infine riassenerà l'indice i alla
    radice. 
*/

template<class Item> void priorityQueue<Item>::IncreasePriority(int i, Item key){

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

#endif //QUEQUE_H