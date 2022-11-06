#ifndef RADIXSORT_H
#define RADIXSORT_H

#include<iostream>
#include<vector>
#include<string>
using namespace std;

template <class Item>
class radixSort{
    private:

        static Item getMax(vector<Item> *A);
        static Item counting(vector<Item> *A, int i);

    public:

        radixSort(/* args */);
        static Item radixsort(vector<Item> *A);
        static void print(vector<Item> );
};

template<class Item> radixSort <Item>::radixSort(/* args */){

}



#endif