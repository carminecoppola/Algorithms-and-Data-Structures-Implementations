#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "nodo.h"

using namespace std;
template <class T>

class linkedList{
    private:
        Nodo<T> *testa;
        Nodo<T> *coda;
    public:
        linkedList();
        ~linkedList();

        Nodo *getTesta(){
            return testa;
        }
        Nodo *getCoda(){
            return coda;
        }
        void printLista();  //Stampa della lista
        void insertList(T *); //Inserimento in Lista

        bool empty();       //Controllo se la lista è vuota
};

//Costruttore
template <class T> linkedList <T>::linkedList(){
    testa = nullptr;
    coda = nullptr;
}

//Distruttore
template <class T> linkedList <T>::~linkedList(){

    while (this->testa != nullptr){
            Nodo *tmp = testa;
            testa = testa ->getNext();
            delete tmp;
        }
    
}

//Metodo per sapere se la lista è vuota
template <class T> bool linkedList<T>::empty(){
    if (this->testa == nullptr){
        return true;
    }
    return false;
}

template <class T> void linkedList<T>::insertList(T *p){

    //Inserimento in coda
    Nodo<T> *ins = new Nodo<T>(p);

    if (! this->empty()){
        coda->setNext(ins);
        coda=ins;
    }
    else{
        coda=testa=ins;
    }
}

#endif //LINKEDLIST_H