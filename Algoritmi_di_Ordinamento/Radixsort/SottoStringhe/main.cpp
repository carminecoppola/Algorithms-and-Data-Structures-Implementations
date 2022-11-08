/*  Progettare ed implementare un algoritmo che dato in input un
    array di stringhe le ordini in modo che ogni stringa sia una
    sottostringa delle successive
        • Es.: [palmare, re, spalmare, mare]
            re
            mare
            palmare
            spalmare
*/

#include<iostream>
#include<vector>
#include<string>
#include"algoritmo.h"

int main(){

    vector<string> A = {"palmare","re","spalmare","mare"};

    cout<<"•Parole inziali: "<<endl;
    algoritmo::print(A);
    algoritmo::countingRadix(&A);
    cout<<"•Parole dopo CountingSort: "<<endl;
    algoritmo::print(A);

    return 0;
}