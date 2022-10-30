#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include<iostream>
#include<vector>
#include"maxHeap.h"
using namespace std;

template<class Item>
class priority_queue : public maxHeap{
    private:

        void maximum(); //Restituisce il massimo
        void minimum();
        void extractMax();  //Rimuove e restituisce l'elemento nell'albero con priorità maggiore
        void extractMin();

    public:
        priority_queue(vector<Item>);
        void insertMH(Item x);  //Restituisce l'elemento nella coda
        void IncreasePriority(int x,int k);    //Aumenta il valore della priorita di x al nuovo valore
        void DecreasePriority();
};

//Costruttore
template<class Item> priority_queue <Item>::priority_queue(vector<Item> albero):maxHeap<Item>(albero){}

template<class Item> void priority_queue <Item>::insertMH(Item x){
    this->insert(x);
}

#endif //QUEQUE_H