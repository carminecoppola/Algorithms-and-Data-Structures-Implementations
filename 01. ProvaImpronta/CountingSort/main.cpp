#include<iostream>
#include<vector>
#include"counting.h"

using namespace std;

int main(){

    vector <int> A = {2, 5, 3, 0, 2, 3, 0, 3};
    counting::countingSortFerone(&A);

    cout<<endl<<"Versione di Ferone"<<endl;
    for (auto i : A)
        cout << i << " ";  
    cout << endl;

    vector <int> A1 = {2, 5, 3, 0, 2, 3, 0, 3};
    vector <int> B1(A1.size());
    counting::countingSortCormen(&A1, &B1);

    cout<<endl<<"Versione Cormen"<<endl;
    for (auto i : B1)
        cout << i << " ";  
    cout << endl;

    vector <int> B = {2, 5, 3, 0, 2, 3, 0, 3};
    counting::countingSortReverse(&B);

    cout<<endl<<"Reverse Ferone"<<endl;
    for (auto i : B)
        cout << i << " ";  
    cout << endl;

    return 0;
}