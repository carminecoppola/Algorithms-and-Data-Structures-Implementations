
#ifndef BLOCCHI_H
#define BLOCCHI_H
#include <iostream>
#include <string>
#include "linkedList.h"
#include "transazioni.h"

using namespace std;

class Blocchi{
    private:
        int id;
        linkedList<Transazioni> *lista;
    public:
        Blocchi(int );
        //~Blocchi();

        void setID(int );
        void setLista(linkedList<Transazioni> *);
        int getID(){
            return id;
        }
        linkedList<Transazioni>* getLista(){
            return lista;
        }

        void insertList(int );
        int printList(string );

};

Blocchi::Blocchi(int i){
    id = i;
    lista = new linkedList<Transazioni>;
}

//Blocchi::~Blocchi(){}

void Blocchi::setID(int i){
     id = i;
}

void Blocchi::setLista(linkedList<Transazioni> *lst){
    lista = lst;
}

void Blocchi::insertList(int ntrans){

        
        string from;
        string to;
        float qt;

        Transazioni *test = new Transazioni(from,to,qt);
        for (int i = 1; i <= ntrans; i++)
        {
            cout<<"----------------------------------------------------------"<<endl;
            cout<<"Inserisci la transazione n. "<< i << "per il blocco n." << getID() << endl;
            cout<<"Inserire il mittente:"<<endl;
            cin>>from;
            cout<<"Inserire il destinatario:"<<endl;
            cin>>to;
            cout<<"Inserire la quantità:"<<endl;
            cin>>qt;
            cout<<"----------------------------------------------------------"<<endl;

            lista->insertList(test);
        }
        
}

int Blocchi::printList(string ind){

    Nodo<Transazioni> *stampa = lista->getTesta();
    int bilancio = 0;

    while (stampa != nullptr){
        if (ind == stampa->getInfo()->getFrom()){

            cout<<"From"<<stampa->getInfo()->getFrom()<<endl<<"To"<<stampa->getInfo()->getTo()<<endl
            <<"QT"<<stampa->getInfo()->getQt()<<endl;
            bilancio -= stampa->getInfo()->getQt(); //Toglie la quantità
        }
        else if(ind == stampa->getInfo()->getTo()){

            cout<<"From"<<stampa->getInfo()->getFrom()<<endl<<"To"<<stampa->getInfo()->getTo()<<endl
            <<"QT"<<stampa->getInfo()->getQt()<<endl;
            bilancio += stampa->getInfo()->getQt();  //Aggiunge la quantità
        }
        
        stampa = stampa->getNext();
    
    }
    
    return bilancio;
    
}



#endif //BLOCCHI_H