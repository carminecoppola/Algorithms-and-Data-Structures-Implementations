#ifndef VERTICE_H
#define VERTICE_H

#include<iostream>
#include<limits>
#include<string>

using namespace std;

enum class Color{
    WHITE,GRAY,BLACK
};

template<class T>
class Vertice
{
    private:
        T value;
        Color colore;
        Vertice<T> *predecessore;
        int distanza;
    public:
        Vertice(T value);

        //Set
        void setValue(T value){this->value = value;}
        void setColore(Color colroe){this->colore = colore;}
        void setPredecessore(Vertice<T> *predecessore){this->predecessore = predecessore;}
        void setDistanza(int distanza){this->distanza = distanza;}

        //Get
        T getValue(){return value;}
        Color getColore(){return colore;}
        Vertice<T> *getPredecessore(){return predecessore;}
        int getDistanza(){return distanza;}

        //Overload
        friend ostream& operator<<(ostream& out, const Vertice<T>&obj)
        {
            string c;
            switch (obj.colore)
            {
            case Color::WHITE:
                c = "WHITE";
                break;
            case Color::GRAY:
                c = "GRAY";
                break;
            case Color::BLACK:
                c = "BLACK";
                break;
            
            default:
                break;
            }
            out<<"Valore: "<<obj.value <<" Colore: "<<c;
            return out;
        }
    
};

template<class T> Vertice<T>::Vertice(T value)
{
    this->value = value;
    colore = Color::WHITE;
    predecessore = nullptr;
    distanza = UINT16_MAX;
}



#endif