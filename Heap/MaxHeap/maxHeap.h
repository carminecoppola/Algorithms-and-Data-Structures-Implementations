#ifndef MAXHEAP_H
#define MAXHEAP_H

#include<iostream>
#include <vector>
using namespace std;

template <class Item>

class maxHeap{
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

        void maxHeapify(int size); 

        //Metodo di getter per l'Albero
        vector<Item> getAlbero(){
            return albero;
        };
        //Metodo di setting per il Size
        void setSize(int s){
            size = s;
        };
        //Metodo di getter per il Size
        int getSize(){
            return size;
        };

        void swap(Item& a ,Item& b){
            Item t = a;
            a = b;
            b = t;
        };

    public:
        //Costruttore
        maxHeap(vector<Item>alb){
            albero = alb;
            size = 0;
        };
        void buildMaxHeap(); //Costruzione del nostro albero
        void insert(Item elemento);
        void printArray();
        void printAsciiTree();
};

template<class Item> void maxHeap<Item>::maxHeapify(int i){
    int max = i;
    int l = left(max);
    int r = right(max);

    if(l < getSize() && getAlbero().at(max) < getAlbero().at(l)){
            max = l;
    }
    if (r < getSize() && getAlbero().at(max) < getAlbero().at(r)){
        max = r;
    }
    if (max != i){
        swap(albero.at(i),albero.at(max));
        maxHeapify(max);
    }
}

template<class Item> void maxHeap<Item>::buildMaxHeap(){   
    setSize((int)getAlbero().size()); //setto il size dell'albero
    for (int i = getSize()/2; i >= 0 ;i--){
        maxHeapify(i);
    } 
}

template <class Item> void maxHeap<Item>::insert(Item elemento){
    albero.push_back(elemento);      //tramite pushback inserisco l'elemento nell'albero
    setSize(getSize()+1);           //Visto che è stato aggiunto un elemento aggiorno il size
    buildMaxHeap();                //Richiamo la funzione che crea l'albero
}

template <class Item> void maxHeap<Item>::printArray(){
    cout<<"\nStampa dell'albero: \n"<<endl;
    for (int i = 0; i < getSize(); i++){
        cout<< getAlbero().at(i)<<" ";
    }
    cout<<endl;
    
}
#endif 