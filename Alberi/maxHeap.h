#ifndef MAXHEAP_H
#define MAXHEAP_H

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
        void buildMaxHeap();

        //Costruttore
        maxHeap(vector<Item>alb){
            albero = alb;
            size = 0;
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

    public:
        void swap(Item& a ,Item& b){
            Item t = a;
            a = b;
            b = t;
        };
        void insert();
        void printArray();
        void printAsciiTree();
};

template<class Item> void maxHeap<Item>::maxHeapify(int size){
    int max = i;
    int l = left[i];
    int r = right[i];

    if(getAlbero().at(max) < getAlbero().at(l) && l < getSize()){
            max = l;
        }
    if (getAlbero().at(max) < getAlbero().at(r) && r < getSize()){
        max = r;
    }
    if (max != i){
        //Scambia
    }
    
}

#endif MAXHEAP_H