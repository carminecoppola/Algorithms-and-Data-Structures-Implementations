/*  
*/
#include<iostream>
#include<vector>
#include "heapsort.h"

using namespace std;

int main(){

    vector<int> tree{10,15,22,7,40,3};
    heapsort<int> albero = heapsort<int>(tree);

    albero.heapSort();
    albero.printArray();

    return 0;
}
