#ifndef KMAX_H
#define KMAX_H

#include <iostream>
#include <vector>

using namespace std;

template <class Item>
class kMax
{
private:
    /* data */
public:
    kMax(/* args */);
    Item maximum();
    Item minimum();
    Item extractMax();
    Item extractMin();
};

template <class Item>
kMax<Item>::kMax(/* args */)
{
}

#endif