/*  Progettare ed implementare un algoritmo ricorsivo che dato
    un array verifichi se rappresenta un heap binario
*/

#include<iostream>
#include <vector>
#include"isHeap.h"

using namespace std;

int main(){

    vector<int> tree{60,50,30,10,20};
    isHeap<int> albero;

    cout<<"\nE' un albero di tipo MAXHEAP?: "<<albero.isMax(tree,5,0)<<endl;

    return 0;
}