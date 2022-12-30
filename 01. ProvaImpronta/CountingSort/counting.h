#ifndef COUNTING_H
#define COUNTING_H

#include <iostream>
#include<vector>

using namespace std;

class counting
{
    private:
        
    public:

        static void countingSortFerone(vector<int> *a);
        static void countingSortCormen(vector<int> *a ,vector<int> *b);
        static void countingSortReverse(vector<int> *a);

};

void counting::countingSortFerone(vector<int> *a){

    int size = a->size();
    int max = a->at(0);
    int min= a->at(0);

    //Calcolo degli elementi massimo e minimo
    for (int i = 1; i < size; i++)
    {
        if (a->at(i) > max)
            max = a->at(i);
        else if(a->at(i) < min)
            min = a->at(i);
    }

    //Costruzione  dell'array C* che crea un array C di dimensione (max-min+1)

    int sizeC = max - min+ 1;
    int *c = new int[sizeC];

    for(int i = 0; i < sizeC ; i++)
    {
        c[i] = 0;   //Inizzializzo l'array C
    }

    //Aumento il numero di occorrenze del valore
    for (int i = 0; i < size; i++)
    {
        c[a->at(i) - min]++;
    }
    
    //Ordinamento in base al contenuto dell'array delle frequenze C

    int k = 0;
    for (int i = 0; i < sizeC; i++)
    {
        while (c[i] > 0)
        {
            //Scrive C[i] volte il valore (i + min-1) nell'array A
            a->at(k) = i + min;
            k++;
            c[i]--;
        }
        
    }
    delete[]c;

}

void counting::countingSortCormen(vector<int> *a, vector<int> *b)
{
    int sizeA = a->size();
    int max = a->at(0) , min = a->at(0);

    //Calcolo gli elementi massimo e minimo
    for (int i = 1; i < sizeA; i++)
    {
        if(a->at(i) > max)
            max = a->at(i);
        else if(a->at(i) < min)
            min = a->at(i);
    }

    //Costruzione dell'array C * crea un array C di dimensione max - min
    int sizeC = max - min + 1;
    int *c = new int[sizeC]; 
    
    for(int i = 0 ; i < sizeC ; i++)
    {
        c[i] = 0;   //Inizzializzo C
    }

    for (int i = 0; i < sizeA; i++)
    {
        c[a->at(i)]++;
    }

    for (int i = 1; i < sizeC; i++)
    {
        c[i] += c[i-1];
    }
    
    for (int i = sizeA-1; i >= 0; i--)
    {
        b->at(c[a->at(i)]-1) = a->at(i);
        c[a->at(i)]--;
    }

    delete[]c; 
}

void counting::countingSortReverse(vector<int> *a){

    int size = a->size();
    int max = a->at(0);
    int min= a->at(0);

    //Calcolo degli elementi massimo e minimo
    for (int i = 1; i < size; i++)
    {
        if (a->at(i) > max)
            max = a->at(i);
        else if(a->at(i) < min)
            min = a->at(i);
    }

    //Costruzione  dell'array C* che crea un array C di dimensione (max-min+1)

    int sizeC = max - min+ 1;
    int *c = new int[sizeC];

    for(int i = 0; i < sizeC ; i++)
    {
        c[i] = 0;   //Inizzializzo l'array C
    }

    //Aumento il numero di occorrenze del valore
    for (int i = 0; i < size; i++)
    {
        c[a->at(i) - min]++;
    }
    
    //Ordinamento in base al contenuto dell'array delle frequenze C

    int k = 0;
    for (int i = sizeC-1; i >= 0; i--)
    {
        while (c[i] > 0)
        {
            //Scrive C[i] volte il valore (i + min-1) nell'array A
            a->at(k) = i + min;
            k++;
            c[i]--;
        }
        
    }
    delete[]c;

}

#endif