#ifndef KHEAP_H
#define KHEAP_H

#include<iostream>
#include <vector>
using namespace std;

template <class Item>

class kheap{
    private:
        vector<Item> albero;
        int size;
        int k;

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
        kheap(vector<Item>alb, int el){
            albero = alb;
            k = el;
            size = 0;

        };
        void buildMaxHeap(); //Costruzione del nostro albero
        void insert(Item elemento);
        void printArray();
        void printAsciiTree();
};

template<class Item> void kheap<Item>::maxHeapify(int i){
    int max = i;
    int primo = (i*k+1);
    int ultimo = (i*k+k);

    for (int j = primo; j < ultimo; j++){
        if (j < getSize() && getAlbero().at(j) > getAlbero().at(max)){
            max = j;
        } 
    }
    
    if (max != i){
        swap(albero.at(i),albero.at(max));
        maxHeapify(max);
    }
}

template<class Item> void kheap<Item>::buildMaxHeap(){   
    setSize((int)getAlbero().size()); //setto il size dell'albero
    for (int i = getSize()/k; i >= 0 ;i--){
        maxHeapify(i);
    } 
}

template <class Item> void kheap<Item>::insert(Item elemento){
    albero.push_back(elemento);      //tramite pushback inserisco l'elemento nell'albero
    setSize(getSize()+1);           //Visto che è stato aggiunto un elemento aggiorno il size
    buildMaxHeap();                //Richiamo la funzione che crea l'albero passandogli come 
                                  //parametro l'elemento stesso
}

template <class Item> void kheap<Item>::printArray(){
    cout<<"\nStampa dell'albero: \n"<<endl;
    for (int i = 0; i < getSize(); i++){
        cout<< getAlbero().at(i)<<" ";
    }
    cout<<endl;
    
}
#endif 