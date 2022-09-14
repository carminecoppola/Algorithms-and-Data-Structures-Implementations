/*Si  realizzi  un  programma  C  e  Posix  in  ambiente  Linux  che,  impiegando  la  libreria  Pthread,  generi  m  thread per calcolare
    la somma dei prodotti delle colonne di due matrici mxm. L'i-esimo thread, dopo aver calcolato la somma dei prodotti
    delle colonne i-esime delle due matrici, inserisce il risultato in un array m-dimensionale, in modo concorrente, nella prima locazione
    libera disponibile. Non appena l'array sarà riempito, un m+1-esimo thread, che era in attesa, provvederà a stamparne il contenuto. 
    Le matrici devono essere allocate dinamicamente. Usare mutex e variabili di condizione. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#define m 4

// calcolare i prodotti delle collenne e addizzionarli fra di loro
// inserisco in un vettore
// appena il vettore è completo
// un'ulteriore thread stamperà il contenuto

struct fo{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} varC = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER};

int *a;
int *b;
int *c;
int j;

// creazione array
void creaArray(int *a){
    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
            *(a+i*m+j) = rand()%(3-1)+1;
}

// visualizza array
void visualizzaArray(int *a){
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++)
            printf(" %2u", *(a+i*m+j));
        puts("");
    }
}

// trova primo spazio disponibile
int spazio(){
    for (int i=0; i<m; i++)
        if (*(c+i) == 0)
            return i;
    return m;
}

void prodotto(int index){

    int tempA = 1;
    int tempB = 1;
    int tempC = 0;

    for (int i=0; i<m; i++)
        tempA = (*(a+i*m+index)) * tempA;
    for (int i=0; i<m; i++)
        tempB = (*(b+i*m+index)) * tempB;

    tempC = tempA + tempB;
    *(c+j) = tempC;
}

// routine m
void* routine(void *ind){

    int index = *(int*)ind;

    // sezione critica
    pthread_mutex_lock(&varC.mutex);

    j = spazio();

    if ( j == (m-1) ){
        prodotto(index);
        pthread_mutex_unlock(&varC.mutex);
        pthread_cond_signal(&varC.cond);
        pthread_exit(0);       
    } else 
        prodotto(index);
    
    // sezione critica
    pthread_mutex_unlock(&varC.mutex);

    pthread_exit(0);
}

// routine finale
void* lettore(){

    pthread_mutex_lock(&varC.mutex);
    while (j != (m-1))
        pthread_cond_wait(&varC.cond, &varC.mutex);
    
    printf("\nVettore c completo:\n");
    for (int i=0; i<m; i++)
        printf("\n %2u", *(c+i));
    printf("\n");

    pthread_mutex_unlock(&varC.mutex);
    pthread_exit(0);
}

// main
void main(){

    srand(time(NULL));

    a = malloc(m*m*sizeof(int*));
    b = malloc(m*m*sizeof(int*));
    c = malloc(m*sizeof(int*));

    creaArray(a);
    creaArray(b);

    printf("\nArray a:\n");
    visualizzaArray(a);

    printf("\nArray b:\n");
    visualizzaArray(b);

    for (int i=0; i<m; i++)
        *(c+i) = 0;
    printf("\nVettore c:\n");
    for (int i=0; i<m; i++)
        printf("\n %2u", *(c+i));

    pthread_t th[m+1];

    for (int i=0; i<m; i++){
        int *index = malloc(sizeof(int));
        *index = i;
        if (pthread_create(th+i, NULL, &routine, index) != 0)
            printf("\nErrore nella creazione");
    }
    
    if (pthread_create(th+m, NULL, &lettore, NULL) != 0)
            printf("\nErrore nella creazione");

    for (int i=0; i<=m; i++)
        if (pthread_join(th[i], NULL) != 0)
            printf("\nErrore nel join");


}
