/*  Proggettare ed implementare una classe che implementi un 
    heap k-nario(ogni nodo ha k figli)
*/
#include<iostream>
#include<vector>
#include<ctime>
#include "kheap.h"

using namespace std;

int main(){

    vector<int> tree;
    kheap <int> albero = kheap<int>(tree,3);
    
    srand(time(NULL));

    for (int i = 0; i < 13; i++)
    {
        albero.insert(rand()%20);
    }

    cout<<endl<<"L'albero ha k uguale a 3:";
    albero.printArray();

    return 0;
}
