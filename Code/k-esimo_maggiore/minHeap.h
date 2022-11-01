#ifndef MINHEAP_H
#define MINHEAP_H

#include<iostream>
#include <vector>
using namespace std;

template <class Item>
class minHeap{
    private:
        int size;
        int left(int i){
            int sx = (i*2)+1;
            return sx;
        };
        int right(int i){
            int dx = (i*2)+2;
            return dx;
        };

    protected:
        vector<Item> albero;

        int parent(int i){
            int padre = (i-1)/2;
            return padre;
        };
        void swap(Item& a ,Item& b){
            Item t = a;
            a = b;
            b = t;
        };

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

        void minHeapify(int size); 
        void insert(Item elemento);

    public:
        /*Costruttore modificato poichè ci interesserà una coda
          di k elementi.*/
        minHeap(vector<Item>alb, int k){
            albero = alb;
            size = k;
        };
        void buildMinHeap(); //Costruzione del nostro albero
        void printArray();
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

/*Abbiamo modificato il metodo di insert() poichè ci servira
  verificare che l'elemento inserito sia maggiore della radice
  cosi che qualora lo fosse venga inserito nella coda e la radice
  venga tolta. Dopodichè ripristiniamo le proprieta del minHeapify()
  ma lo faremo tramite il buildMinHeap().
*/
template <class Item> void minHeap<Item>::insert(Item elemento){

    //Controllo che l'elemento da inserie sia maggiore della radice
    if (elemento > getAlbero().at(0) ){
        cout<<"L'elemento "<<elemento<<" è > "<<getAlbero().at(0)<<endl;
        albero.at(0) = elemento;
        buildMinHeap();
    }
    else{
        cout<<"L'elemento "<<elemento<<" è piu piccolo quindi viene scartato"<<endl;
    }
}


template <class Item> void minHeap<Item>::printArray(){
    cout<<"\nStampa dell'albero: \n"<<endl;
    for (int i = 0; i < getSize(); i++){
        cout<< getAlbero().at(i)<<" ";
    }
    cout<<endl;
    
}
#endif 