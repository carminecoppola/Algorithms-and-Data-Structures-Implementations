#ifndef MINHEAP_H
#define MINHEAP_H

#include<iostream>
#include <vector>
using namespace std;

template<class Item>

class minHeap{
    private:
        vector<Item> albero;
        int size;

        int parent(int i){
            int padre = (i+1)/2;
            return padre;
        };

        int left(int i){
            int sx = (i*2)+1;
            return sx;
        };

        int right(int i){
            int dx = (i*2)+2;
            return dx;
        };

        void minHeapify(int size);

        //Metodo di getter per l'albero
        vector<Item> getAlbero(){
            return albero;
        };
        //Metodo di setting per il size
        void setSize(int s){
            size = s;
        };
        //Metodo di getter per il size
        int getSize(){
            return size;
        };

        //Metodo di Swap
        void swap(Item& a ,Item& b){
            Item t = a;
            a = b;
            b = t;
        };

        void buildMinHeap(); //Costruzione del nostro albero

    public:
        minHeap(vector<Item> al){
            albero = al;
            size = 0;
        };

        int somma(int elemento,int radice);
        void insert(Item elemento);
        void printArray();
        void printAsciiTree();

};

template<class Item> void minHeap<Item>::minHeapify(int i){
    int min = i;
    int l = left(min);
    int r = right(min);

    if(l < getSize() && getAlbero().at(min) > getAlbero().at(l)){
            min = l;
        }
    if (r < getSize() && getAlbero().at(min) > getAlbero().at(r)){
        min = r;
    }
    if (min != i){
        swap(albero.at(i),albero.at(min));
        minHeapify(min);
    }
}

template<class Item> void minHeap<Item>::buildMinHeap(){   
    setSize((int)getAlbero().size()); //setto il size dell'albero
    for (int i = getSize()/2; i >= 0 ;i--){
        minHeapify(i);
    } 
}

template <class Item> void minHeap<Item>::insert(Item elemento){
    albero.push_back(elemento);      //tramite pushback inserisco l'elemento nell'albero
    setSize(getSize()+1);           //Visto che è stato aggiunto un elemento aggiorno il size
    buildMinHeap();                //Richiamo la funzione che crea l'albero
}

template <class Item> void minHeap<Item>::printArray(){
    cout<<"\nStampa dell'albero: \n"<<endl;
    for (int i = 0; i < getSize(); i++){
        cout<< getAlbero().at(i)<<" ";
    }
    cout<<endl;
    
}

template <class Item> int minHeap<Item>::somma(int elemento, int radice){

    if (radice >= getSize()){       //Caso Base
        return 0;
    }
    if (getAlbero().at(radice) >= elemento){    //Caso base
        return 0;
    }
    
    int risultato = getAlbero().at(radice)+somma(elemento,left(radice))+somma(elemento,right(radice));

    return risultato;

}

#endif