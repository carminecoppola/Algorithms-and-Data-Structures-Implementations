/*  Dato un array di n elementi, trovare il massimo numero di
    elementi distinti dopo aver rimosso k elementi (k <= n)
    • Esempio: {5,4,4,3,4,6,2,1,2}, per k=2 maxnum=5(5,3,6,2,1),
      per k=3 maxnum=6(5,4,3,6,2,1)
*/

#include<iostream>
#include<map>
#include<vector>
#include"priorityQueue.h"
#include"maxHeap.h"

using namespace std;

int main(){

    vector<int> sequenza{5,4,4,3,4,6,2,1,2};
    map<int,int> occorrenze;
    map<int,int>::iterator it;
    int num;

    for (int i = 0; i < sequenza.size(); i++)    
    {
        num = sequenza.at(i);

        it = occorrenze.find(num);

        if (it == occorrenze.end())
        {
            occorrenze.insert(make_pair(num,1));    //inserisce correttamente il numero (numero,occorrenza)
        }
        else{
            occorrenze.at(num)++;
        }
        
    }

    for (it = occorrenze.begin(); it != occorrenze.end(); it++)
    {
        cout<< (*it).first << " ---> " << (*it).second <<endl;  //first() indica il numero mentre second l'occorrenze()
    }
    
    

    return 0;
}