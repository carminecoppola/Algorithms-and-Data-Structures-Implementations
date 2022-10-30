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

        void maxKHeapify(int size); 

    public:
        //Costruttore
        kheap(vector<Item>alb, int el){
            albero = alb;
            k = el;
            size = 0;

        };
        void buildMaxKHeap(); //Costruzione del nostro albero
        void insert(Item elemento);
        void printArray();
};

template<class Item> void kheap<Item>::buildMaxKHeap(){   
    setSize((int)getAlbero().size()); //setto il size dell'albero

    for (int i = getSize()/k; i >= 0 ;i--){
        maxKHeapify(i);
    } 
}

template<class Item> void kheap<Item>::maxKHeapify(int i){
    int max = i;
    int primo = (i*k+1);
    //int primo = k * (i+1);
    //int ultimo = k * i + 1;
    int ultimo = (i*k+k);

    for (int j = primo; j <= ultimo; j++){
        if (j < getSize() && getAlbero().at(j) > getAlbero().at(max)){
            max = j;
        } 
    }
    
    if (max != i){
        swap(albero.at(max),albero.at(i));
        maxKHeapify(max);
    }
}

template <class Item> void kheap<Item>::insert(Item elemento){
    
    setSize(getSize()+1);             //Visto che è stato aggiunto un elemento aggiorno il size
    albero.push_back(elemento);      //tramite pushback inserisco l'elemento nell'albero
    buildMaxKHeap();                //Richiamo la funzione che crea l'albero passandogli come 
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