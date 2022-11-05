/*Implementare counting sort*/

#include<iostream>
#include<vector>
#include"countingsort.h"

using namespace std;

int main(){

    vector<int> numeri{2,5,3,0,2,3,0,3};

    cout<<endl<<"Array Iniziale:"<<endl;
    for (auto i : numeri){
       cout<< i <<" ";
    }
    cout<<endl;
    
    //CountingSort Base
    countingsort::counting(&numeri);
    cout<<endl<<"Array dopo CountingSort Base:"<<endl;
    for (auto i : numeri){
        cout<< i <<" ";
    }
    cout<<endl;
    
    //CountingSort Cormen
    vector<int> B(numeri.size());
    countingsort::countingCormen(&numeri,&B);

    cout<<endl<<"Array dopo CountingSort Cormen:"<<endl;
    for (auto i : B){
        cout<< i <<" ";
    }
    cout<<endl;

    //CountingSort Inverso
    countingsort::countingInverso(&numeri);
    cout<<endl<<"Array dopo CountingSort Inverso:"<<endl;
    for (auto i : numeri){
        cout<< i <<" ";
    }
    cout<<endl;

    return 0;
}