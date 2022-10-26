#ifndef ISHEAP_H
#define ISHEAP_H

#include<iostream>
#include <vector>
using namespace std;

template <class Item>
class isHeap{

    private:

        int parent (int i){
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
    public:
        bool isMax(vector<Item> alb ,int size,int radice);
        bool isMin(vector<Item> alb ,int size,int radice);
};

template<class Item> bool isHeap<Item>::isMax(vector<Item> alb ,int size,int radice){

    int l = left(radice);
    int r = right(radice);

    if (radice >= size/2){
        return true;
    }
    if (alb.at(radice) < alb.at(l) && l < size){
        return false;
    }
    if (alb.at(radice) < alb.at(r) && r < size){
        return false;
    }
    
    return isMax(alb,size,l) && isMax(alb,size,r);
    

}

template<class Item> bool isHeap<Item>::isMin(vector<Item> alb ,int size,int radice){


}


#endif