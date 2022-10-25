#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "vector"
using namespace std;

template <class Item>

class maxHeap{
    private:
        vector<Item> albero;
        int size;
        int padre(int i){
            int parent = (i+1)/2;
            return parent;
        };
        int sinistro(int i){
            int sx = (i*2)+1;
            return sx;
        };
        int destro(int i){
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

        void getAlbero(vector<Item> al){
            return al;
        };

        void setSize(int s){
            size = s;
        };
        int getSize(int s){
            return s;
        };


    public:
        void insert();
        void printArray();
        void printAsciiTree();
};



#endif MAXHEAP_H