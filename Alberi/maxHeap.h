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

        void maxHeapify();
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
        void insert();
        void printArray();
        void printAsciiTree();
};

template<class Item> void maxHeap::maxHeapify(){

}

#endif MAXHEAP_H