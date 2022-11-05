/*Implementare counting sort*/

#include<iostream>
#include<vector>
#include"countingsort.h"

using namespace std;

int main(){

    vector<int> array{2,5,3,0,2,3,0,3};

    
    
    



    //Cormen
    vector<int> B(array.size());
    countingsort::countingCormen(&array,&B);

    cout<<"Counting Sort Cormen:"<<endl;
    for (auto i : B){
        cout<< i <<" ";
    }
    cout<<endl;

    return 0;
}