#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <iostream>
#include<vector>

using namespace std;

template < class T >
class algoritmo
{
private:

    void swap(int &a,int &b);
    void static partition();

public:

    void static quickSort();
};

template<class T> void algoritmo<T>::swap(int &a,int &b){

}

#endif