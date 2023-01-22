#ifndef VERTICE_H
#define VERTICE_H

#include<iostream>
#include<string>
#include<limits>

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

        //metodi di set
        void setValue(T value){this->value = value;}
        void setColore(Color colore){this->colore = colore;}
        void setPredecessore(Vertice<T> *predecessore){this->predecessore = predecessore;}
        void setDistanza(int distanza){this->distanza = distanza;}

        T getValue(){return value;}
        Color getColore(){return colore;}
        Vertice<T> *getPredecessore(){return predecessore;}
        int getDistanza(){return distanza;}

        friend ostream& operator<<(ostream &out, const Vertice<T> obj)
        {
            string c;
            switch(obj.colore)
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
            out<<"Valore: "<<obj.value << " Colore: "<<c;
            return out;
        }

        friend bool operator == (Vertice<T> &a, const Vertice<T> &b)
        {
            return a.vale == b.value;
        }
};

template <class T> Vertice<T>::Vertice(T value)
{
    this->value = value;
    colore = Color::WHITE;
    predecessore = nullptr;
    distanza = UINT16_MAX;
}

#endif