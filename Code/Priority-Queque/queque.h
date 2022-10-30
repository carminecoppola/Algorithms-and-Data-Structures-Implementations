#ifndef QUEQUE_H
#define QUEQUE_H

#include<iostream>
#include<vector>
#include"maxHeap.h"
using namespace std;

template<class Item>
class queque : public maxHeap{
    private:

        void maximum();
        void minimum();
        void extractMax();
        void extractMin();

    public:
        queque(vector<Item>);
        void inset();
        void IncreasePriority();
        void DecreasePriority();
};

template<class Item> queque <Item>::queque(vector<Item> albero):maxHeap<Item>(albero){


}


#endif //QUEQUE_H