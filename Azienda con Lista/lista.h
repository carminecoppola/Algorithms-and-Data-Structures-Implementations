#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "nodi.h"
#include "impiegato.h"

using namespace std;

class Lista{
    private:
        Nodi *head;
        Nodi *tail;
    public:
        Lista();    //Costruttore

        Nodi *getHead(){
            return head;
        }
        Nodi *getTail(){
            return tail;
        }
        void printLista();  //Stampa della lista
        void insLista(Impiegato *);

        void somma();
        bool empty();
};

//Costruttore
Lista::Lista(){
    head = nullptr;
    tail = nullptr;
}

//Distruttore
Lista::~Lista(){
    while (this->head != nullptr){
        Nodi *tmp = head;
        head = head ->getNext();
        delete tmp;
    }
    
}

//Controllo se la lista è vuota:
//Se il puntatore alla testa della lista è uguale 
//a NULLPTR allora significa che è vuota
bool Lista::empty(){
    if (this->head == nullptr){
        return true;
    }
    return false;
}

void Lista::insLista(Impiegato *p){

    Nodi *ins = new Nodi(p);

    if (! this->empty()){
        tail->setNext(ins);
        tail=ins;
    }
    else{
        tail=head=ins;
    }
}

void Lista::printLista(){

    Nodi *ogg = head;

    while (ogg != nullptr)
    {
        ogg -> getInfo()->printInfo();
        ogg = ogg->getNext();
        cout<<endl;
    }
    
}

void Lista::somma()
{
    Nodi *i = head;
    Impiegato sum("",0);


    while( i != nullptr)
    {
       Impiegato temp("", i->getInfo()->getSalario());

        sum = sum + temp;
        i = i ->getNext();
    }

    cout << "La somma dei salari: "<<sum.getSalario()<<endl;
}

#endif //LISTA_H