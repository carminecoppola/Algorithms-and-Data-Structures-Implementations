
#include <iostream>
#include <vector>

using namespace std;
//template <typename Item>

int main(){

    vector<int> aux={6,5,4,1,2,3};
    typename vector<int>::iterator it;
    typename vector<int>::iterator jt;
    typename vector<int>::iterator kt;
    
    auto centro = (int)(aux.size()/2)-1;    //-1 perchè approssimiamo per difetto
    auto mediano = aux.begin();
    advance(mediano,aux.size()/2);  //Consente di spostare l'indice della posizione che si vuole
    vector<int> a(aux.size());

    cout << "Indici di partenza"<<endl;
    cout << "Cen: "<< centro << endl;           //Dovrebbe puntare all'elemento centrale (4)
    cout << "Med: "<< *mediano <<endl<<endl;    
    
    //Mi stampo l'array iniziale
    for(auto& i : aux){
        cout << i << " ";
    }
    cout<<endl<<endl;

    //Parte di SX
    for (it = mediano-1; it != aux.begin()-1; it++){
        cout<<"It: "<<*it<<endl;
        cout<<"Cent: "<<centro<<endl;
        a.at(centro) = *it;
        centro--;
        //cout<<"It: "<<*it<<endl;
        //cout<<"Med: "<<*mediano<<endl;
        //cout<<"Cent: "<<centro<<endl;
    }
    

    cout<<"Indici dopo parte Sx"<<endl;
    cout<<"Cen: "<< centro << endl;
    cout<<"Mid: "<< *mediano <<endl<<endl;
    cout<<"Array nuovo:"<<endl;
    for(auto& i : a){
        cout << i << " ";
    }
    cout<<endl<<endl;

    //Parte di DX
    for (jt = mediano; jt != aux.end(); jt++)
    {
        a.at(centro-1) = *jt;
        centro--;
    }

    cout<<"Indici dopo parte Dx"<<endl;
    cout<<"Cen: "<< centro << endl;
    cout<<"Mid: "<< *mediano <<endl<<endl;
    
    for(auto& i : a){
        cout<< i <<" ";
    }
    cout<<endl;

    //Reimposto il valore di dei puntatori all'inizio e alla fine dell'array
    it = a.begin();
    jt = a.end()-1;

    //Riordino l'array finale
    for (kt = a.begin(); kt < a.end(); kt++){

        if (*jt<*it){
            *kt = *jt;
            jt--;
        }
        else{
            *kt=*it;
            it++;
        }
    }
    
}