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

        void swap(Item& a ,Item& b);

    public:
        heapsort(vector<Item> alb);

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


#endif //HEAPSORT_H