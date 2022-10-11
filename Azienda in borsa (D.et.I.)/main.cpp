/*      Un'azienda è quotata in borsa. Si supponga di avere un array
        A[1...N] contenente la quotazione delle azioni in un periodo di
        N giorni e che A[1]<A[N]. È possibile dimostrare che esiste
        almeno una coppia di giorni consecutivi i, i+1 tali che
        A[i]<A[i+1].
        Progettare ed implementare un algoritmo divide-et-impera che
        trovi un indice i che verifichi la condizione data
                    |20|15|13|12|21|  --> la coppia da restituire è |12|21|
*/

#include <iostream>
#include <vector>

using namespace std;
int ricerca_coppia(int[],int ,int );

int main(int argc, char const *argv[])
{
    int a[]={20,15,13,12,21};

    int ind = ricerca_coppia(a,0,4);
    cout<<"L'indice è: "<< ind<<endl;
    cout<<"La coppia è: "<< a[ind] <<" "<< a[ind+1] <<endl<<endl;

    return 0;
}

int ricerca_coppia(int arr[],int start ,int end){

    int mediano;
    int ind;

    //1)Il caso base è quando siamo arrivati ad avere
    //soltanto due elementi dell'array oppure quando
    //la coppia da cercare è uguale al mediano <
    //dell'elemento successivo al mediano (A[i]<A[i+1])

    if ( end+1-start == 1){
        if (arr[start]< arr[end]){
            return start;
        }
        else
            return -1;
    }

    else{
        mediano=(start+end)/2;

        if (arr[mediano] < arr[mediano+1]){
            return mediano;
        }
        else{
            ind = ricerca_coppia(arr,start,mediano);
                if (ind == -1){
                    return ricerca_coppia(arr,mediano+1,end);
            }
            else
                return ind;
            
        }
    }
}