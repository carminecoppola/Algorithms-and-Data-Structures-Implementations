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

    /*  
        Il caso base si ha quando abbiamo solo due numeri 
        e che rispettano la condizione A[i]<A[i+1]
        Altrimenti ritornerà -1
     */

    if ( end+1-start == 1){
        if (arr[start]< arr[end]){
            return start;
        }
        else
            return -1;
    }

    /*
        Nel caso in cui non ci troviamo nel caso base allora
        dovremmo operare ricorsivamente.
         1)Troviamo il mediano;
         2)Il primo controllo da fare è se il mediano è < del 
           suo successivo (mediano+1);
         3)Qualora questa condizione non fosse verificata allora
           bisogna esaminare la porzione di SX;
         4)Se non è presente a SX per forza dovremmo trovarla nella
           porzione di DX;
         5)Ovviamente ritorniamo sempre l'indice della posizione minore;
    */
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