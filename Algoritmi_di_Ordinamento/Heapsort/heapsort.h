#ifndef HEAPSORT_H
#define HEAPSORT_H

#include<iostream>
#include <vector>
using namespace std;

template <class Item>
class heapsort{
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

        //Metodo per scambiare
        void swap(Item& a ,Item& b);

    public:
        heapsort(vector<Item> alb); //Costruttore

        void heapSort();    //Metodo Heap
        void buildMaxHeap(); //Costruzione del nostro albero
        void printArray();

};

template <class Item> heapsort<Item>::heapsort(vector<Item> alb){
    albero = alb;
    size = 0;
}

template <class Item> void heapsort<Item>::swap(Item& a ,Item& b){
    Item t = a;
    a = b;
    b = t;
};

template<class Item> void heapsort<Item>::heapSort(){
    buildMaxHeap();
    for (int i = getSize()-1; i > 0; i--){
        swap(albero.at(0),albero.at(i));    
        setSize(getSize()-1);       //Decremento il size
        maxHeapify(0); //Passo il primo elemento dell'albero quindi la radice
    }
    
}

template<class Item> void heapsort<Item>::maxHeapify(int i){
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

template<class Item> void heapsort<Item>::buildMaxHeap(){   
    setSize((int)getAlbero().size()); //setto il size dell'albero
    for (int i = getSize()/2; i >= 0 ;i--){
        maxHeapify(i);
    } 
}

template <class Item> void heapsort<Item>::printArray(){
    cout<<"\nStampa dell'albero: \n"<<endl;
    for (int i = 0; i < albero.size(); i++){
        cout<< albero.at(i)<<" ";   //Prendiamo gli elementi passati dal vettore poichè non abbiamo più insert
    }
    cout<<endl;
    
}

#endif //HEAPSORT_H