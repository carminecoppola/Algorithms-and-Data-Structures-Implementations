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
        bool isMax(vector<Item> alb ,int size,int radice);
        bool isMin(vector<Item> alb ,int size,int radice);

    public:
        void is(vector<Item> alb ,int size,int radice);
};

template<class Item> bool isHeap<Item>::isMax(vector<Item> alb ,int size,int radice){

    int l = left(radice);
    int r = right(radice);

    if (radice >= size/2){
        return true;
    }
    if (l < size && alb.at(radice) < alb.at(l)){
        return false;
    }
    if (r < size && alb.at(radice) < alb.at(r)){
        return false;
    }
    
    return isMax(alb,size,l) && isMax(alb,size,r);
    

}

template<class Item> bool isHeap<Item>::isMin(vector<Item> alb ,int size,int radice){

    int l = left(radice);
    int r = right(radice);

    if (radice >= size/2){
        return true;
    }
    if (l < size && alb.at(radice) > alb.at(l)){
        return false;
    }
    if (r < size && alb.at(radice) > alb.at(r)){
        return false;
    }
    return isMin(alb,size,l) && isMin(alb,size,r);
}

template<class Item> void isHeap<Item>::is(vector<Item> alb ,int size,int radice){

    
    if (isMax(alb,size,radice) && !isMin(alb,size,radice)){
        cout<<endl<<"**L'albero è un MaxHeap..."<<endl<<endl;
    }
    else if (!isMax(alb,size,radice) && isMin(alb,size,radice))
    {
        cout<<endl<<"**L'albero è un MinHeap..."<<endl<<endl;
    }
    else{
        cout<<endl<<"**L'albero non è nessun Heap..."<<endl<<endl;
    }
}


#endif