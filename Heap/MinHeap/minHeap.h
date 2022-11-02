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

    public:
        minHeap(vector<Item> al){
            albero = al;
            size = 0;
        };

        int somma(int elemento,int radice);
        void insert(Item elemento);
        void buildMinHeap(); //Costruzione del nostro albero
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
    //buildMinHeap();                //Richiamo la funzione che crea l'albero

    int i = getSize()-1;
    while (i>0 && getAlbero().at(parent(i))>elemento)
    {
        swap(albero.at(i),albero.at(parent(i)));
        i = parent(i);
    }
    
}

template <class Item> void minHeap<Item>::printArray(){
    cout<<"\nStampa dell'albero: \n"<<endl;
    for (int i = 0; i < getSize(); i++){
        cout<< getAlbero().at(i)<<" ";
    }
    cout<<endl;
    
}

template <class Item> int minHeap<Item>::somma(int elemento, int radice){

    if (radice >= getSize()){       //Caso Base -> se la radice è maggiore della dimensione dell'albero
        return 0;
    }
    if (getAlbero().at(radice) >= elemento){    //Secondo Caso base -> se l'elemento è minore della radice non avra elementi da sommare
        return 0;
    }
    
    //Sommo gli elementi scorrendo l'albero prima da sinista e poi da destra
    int risultato = getAlbero().at(radice)+somma(elemento,left(radice))
                    +somma(elemento,right(radice));

    return risultato;

}

#endif