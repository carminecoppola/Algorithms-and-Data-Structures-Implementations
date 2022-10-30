#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include<iostream>
#include<vector>
#include"maxHeap.h"
using namespace std;

template<class Item>
class priority_queue : public maxHeap<Item>{
    private:

    public:
        priority_queue(vector<Item>);
        Item maximum(); //Restituisce il massimo
        void minimum();
        Item extractMax();  //Rimuove e restituisce l'elemento nell'albero con priorità maggiore
        void extractMin();
        void insertMH(Item x);  //Restituisce l'elemento nella coda
        void IncreasePriority(int x,int k);    //Aumenta il valore della priorita di x al nuovo valore
        void DecreasePriority();
};

//Costruttore
template<class Item> priority_queue <Item>::priority_queue(vector<Item> albero):maxHeap<Item>(albero){}

template<class Item> void priority_queue <Item>::insertMH(Item x){
    this->insert(x);

}

template<class Item> Item priority_queue <Item>::maximum(){
    return this->getAlbero().at(0);
}

template<class Item> Item priority_queue <Item>::extractMax(){

    if (this->getSize() == 0){
        return -1;
    }
    int max = maximum();

    swap(this->albero.at(0),this->albero.at(this->getSize()-1));
    this->setSize(this->getSize()-1);
    this->maxHeapify(0);

    return max;
    
}



#endif //QUEQUE_H