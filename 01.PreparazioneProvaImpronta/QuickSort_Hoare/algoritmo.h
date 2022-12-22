#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <iostream>
#include<vector>

using namespace std;

template < class T >
class algoritmo
{
private:

    static void swap(T &a,T &b);
    static typename vector<T>::iterator partition(typename vector<T>::iterator l,typename vector<T>::iterator r);

public:

    void static quickSort(typename vector<T>::iterator l, typename vector<T>::iterator r);
};

template<class T> void algoritmo<T>::swap(T &a,T &b){

    T temp = a;
    a = b;
    b = temp;
    
}

//Partition Hoare
template <class T> typename vector<T>::iterator algoritmo <T>::partition(typename vector<T>::iterator l,typename vector<T>::iterator r){

    typename vector<T>::iterator i; 
    typename vector<T>::iterator j;
    
    i = l-1;
    j = r; 

    T pivot = *r;

    for(;;){

        while (*(++i) < pivot);
        while (pivot < *(--j))
            if (j == l)
                break;
        if (i >= j)
            break;
        swap(*i, *j);
    }
    swap(*i,*r);
    return i;
}

template<class T> void algoritmo<T>::quickSort(typename vector<T>::iterator l, typename vector<T>::iterator r){

    if (r <= l)
        return;
    auto i = partition(l,r);
    quickSort(l,i-1); 
    quickSort(i+1,r); 
}

#endif