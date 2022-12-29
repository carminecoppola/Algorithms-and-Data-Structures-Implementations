#include <iostream>
#include <vector>
#include"priority_queue.h"
#include"maxHeap.h"

using namespace std;
int main(){

    vector<int> tree = {25, 30, 20, 3, 2, 4};

    maxHeap<int> t = maxHeap<int>(tree);
    cout<<endl<<"Albero: "<<endl;
    t.printArray();

    t.heapSort();
    cout<<endl<<"Albero ordinato: "<<endl;
    t.printArray();

    t.insert(70);
    t.heapSort();
    cout<<endl<<"Albero ordinato dopo inserimento : "<<endl;
    t.printArray();

}