/*
    • Utilizzando il paradigma della programmazione ad oggetti ed il linguaggio C++ 11, progettare ed
    implementare, come classe, una struttura dati max-heap che consenta di ordinare, mediante algoritmo heapsort,
    un insieme di valori numerici letti dal file heap.txt
*/

#include<iostream>
#include<vector>
#include<fstream>
#include<string>

#include"HeapSort.h"

using namespace std;

int main(){

    string heap = "heap.txt";
    fstream myFile;
    string file;
    vector<int> vect;

    myFile.open(heap.c_str(),ios::in);

    while(getline(myFile,file))
        vect.push_back(stof(file));     //stof mi permette di convertire le stringhe in numeri

    for(auto i:vect)
        cout<<i<<endl;

    //Applico HEAPSORT

    cout<<endl<<"File ordinato: "<<endl;
    HeapSort<int> tree = HeapSort<int>(vect);
    tree.heapSort();
    tree.printArray();

    myFile.close();

    return 0;
}