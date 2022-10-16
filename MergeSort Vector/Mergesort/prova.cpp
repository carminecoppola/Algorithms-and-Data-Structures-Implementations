
#include <iostream>
#include <vector>

using namespace std;
//template <typename Item>

int main(){

    vector<int> aux={4,5,6,1,2,3};
    typename vector<int>::iterator it;
    typename vector<int>::iterator jt;
    typename vector<int>::iterator kt;
    typename vector<int>::iterator low;
    typename vector<int>::iterator high; 
    
    low = aux.begin();
    high = aux.end();

    int size = high-low;

    auto centro = (int)(size/2)-1;    //-1 perchè approssimiamo per difetto
    auto mediano = low;

    advance(mediano,size/2);  //Consente di spostare l'indice della posizione che si vuole
    vector<int> a(size);    

    //Mi stampo l'array iniziale
    for(auto& i : aux){
        cout << i << " ";
    }
    cout<<endl<<endl;

    //Parte di SX
    for (it = mediano-1; it != aux.begin()-1; it--){

        a.at(centro) = *it;
        centro--;
        //Stampo array iniziale
        cout<<"Array iniziale:"<<endl;
        for(auto& i : aux){
            cout << i << " ";
        }
        cout<<endl<<endl;
        //Stampo array d'appoggio
        cout<<"Stampo l'array d'appoggio: "<<endl;
        for(auto& i : a){
            cout << i << " ";
        }
        cout<<endl<<endl;
    }
    
    cout<<"Array nuovo:"<<endl;
    for(auto& i : a){
        cout << i << " ";
    }
    cout<<endl<<endl;

    centro=size;
    //Parte di DX
    for (jt = mediano; jt != aux.end(); jt++)
    {   
        a.at(centro-1) = *jt;
        centro--;

        cout<<"Array iniziale:"<<endl;
        for(auto& i : aux){
            cout<< i <<" ";
        }
        cout<<endl;

        cout<<"Array temporaneo:"<<endl;
        for(auto& i : a){
            cout<< i <<" ";
        }
        cout<<endl;
    }
    
    cout<<"Array Temporaneo prima del for:"<<endl;
    for(auto& i : a){
        cout<< i <<" ";
    }
    cout<<endl;

    //Reimposto il valore di dei puntatori all'inizio e alla fine dell'array
    it = a.begin();
    jt = a.end()-1;

    //Riordino l'array finale
    for (kt = aux.begin(); kt != aux.end(); kt++){
        if (*jt<*it){
            *kt = *jt;
            jt--;
        }
        else{
            *kt=*it;
            it++;
        }
    
    }
    
    cout<<"Array iniziale:"<<endl;
        for(auto& j : aux){
            cout<< j <<" ";
        }
        cout<<endl;

}