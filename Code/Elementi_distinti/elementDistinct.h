#ifndef ELEMENT_DISTINCT_H
#define ELEMENT_DISTINCT_H

#include<iostream>
#include<map>

template<class Item>
class elementDistinct : public maxHeap<Item>{
    private:
        
    public:
        elementDistinct(/* args */);
        ~elementDistinct();
};

template<class Item> elementDistinct <Item>::elementDistinct(/* args */){}

template<class Item> elementDistinct <Item>::~elementDistinct(){}


#endif  //ELEMENT_DISTINCT_H