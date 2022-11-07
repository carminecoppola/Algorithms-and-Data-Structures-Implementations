#ifndef RADIXSORT_H
#define RADIXSORT_H

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class radixSort{
    private:

    public:

        static void countingRadix(string *A,int size, int k);
        static void print(string *A,int size);
};

void radixSort::countingRadix(string *A,int size,int k){

    string *output = new string [size];    //Array di output

    for (int i = k-1; i >= 0; i--)
    {
        int count[26] = {0};             //Array delle occorrenze inizializzato a zero
        for (int j = 0; j < size; j++)
        {
            if (A[j][i] == 'z')
                continue;
            count[(A[j][i])-96]++;
        }

        for (int j = 1; j < 26; j++)
        {
            count[j] += count[j-1];
        }
        
        for (int j = 0; j < size; j++)
        {
            output[count[(A[j][i])-97]] = A[j];
            count[(A[j][i])-97]++;
        }

        for (int j = 0; j < size; j++)
        {
            A[j] = output[j];
        }       
    } 
}


void radixSort::print(string *A,int size){

    for (int i = 0; i < size; i++){
        cout<<" "<<A[i]<<endl;
    }
    cout<<endl;
    

}

#endif