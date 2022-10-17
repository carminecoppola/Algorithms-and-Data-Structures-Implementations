#ifndef RICORSIVO_H
#define RICORSIVO_H

using namespace std;

template <class Item>

class ricorsivo{

    private:
        void static mergericorsivo(Item *,Item *,int ,Item *,int );
    public:
        void static mergesort(Item [],int , int );
};

template <class Item> void ricorsivo <Item>::mergericorsivo(Item *C,Item *A,int N,Item *B,int M){

    //Controllo se ci sono elementi nei due array
    if (N && M){    
        if (A[0] > B[0]){
            C[0] = B[0];    //Prendo l'elemento di B
            mergericorsivo(C+1,A,N,B+1,M-1); //Chiamata ricorsiva con avanzamento al prossimo elemento di B e C
        }
        else{
            C[0] = A[0];     //Prendo l'elemento di A
            mergericorsivo(C+1,A+1,N-1,B,M); //Chiamata ricorsiva con avanzamento al prossimo elemento di A e C
        }
    }  
    //Se ci sono ancora elementi in A o in B
    else if (M){
        C[0] = B[0];        //Si poteva scrivere anche C = B poichè intende sempre l'indirizzo base
        mergericorsivo(C+1,A,N,B+1,M-1);    //Qui facendo C+1 e  B+1 io vado a cambiare l'indirizzo
                                           //base impostandolo alla posizione successiva;
    }
    else if (N){
        C[0] = A[0];        //Si poteva scrivere anche C = A poichè intende sempre l'indirizzo base
        mergericorsivo(C+1,A+1,N-1,B,M);  //Qui facendo C+1 e  A+1 io vado a cambiare l'indirizzo
                                         //base impostandolo alla posizione successiva;
    }
    

}

template <class Item> void ricorsivo <Item>::mergesort(Item a[],int left,int right){

    //int size = right-left;
    if (left < right){
        int center = (left+right)/2;
        mergesort(a,left,center);
        mergesort(a,center+1,right);

        //Calcolo l'elementi totali dell'array A
        int tot_el_sx = center - left + 1;

        //Calcolo l'elementi totali dell'array B
        int tot_el_dx = right - center;

        //Creo il size di output
        int tot_out = right-left+1;

        //Creo l'array di output
        Item *out = new Item[tot_out];

        //Fondiamo i due sottoarray
        mergericorsivo(out,a+left,tot_el_sx,a+(center+1),tot_el_dx); 

        //Ricopio l'array temporaneo nell'array iniziale
        for (int i = 0;i < right-left + 1;i++){
            a[left+i] = out[i];
        }
            delete []out;

    }
    
}
#endif //RICORSIVO_H