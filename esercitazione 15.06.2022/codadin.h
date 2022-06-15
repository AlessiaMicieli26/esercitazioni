#ifndef CODAS_H
#define CODAS_H
#include <iostream>
using namespace std;
#include "Shape.h"

class Coda_Statica{
    int maxSize = -1; //dimensione massima dell'array;
    int size=0; //elementi inseriti array
    Shape ** array; //array di tipo generico

    int head= -1;   //indice della testa array
    int tail= -1;   //indice della coda array
    
    public:
        Coda_Statica(int maxSize) : maxSize(maxSize){
            array = new Shape*[maxSize];
        }

        void enqueue(Shape * val){
            if(size == maxSize - 1) return; //vuol dire che tutto l'array è riempito di elementi e non posso aggiungerne altri

            if(head==-1) head=0;

            tail= (++tail % maxSize);   //se l'array non è riempito al massimo e sono alla fine di questo array, vuol dire che le prime posizioni
            array[tail]=val;    //si sono liberate, di conseguenza facendo il modulo tra l'indice della coda e la dimensione massima, riparto dalla prima posizione
            size++; //infatti se tail=4 e maxsize=4 allora 4mod4 -> 0 qundi ritorno alla posizione 0 e posso inserire il mio elemento
            return;
        }

        Shape * dequeue(){
            if(size==0){
                return nullptr;
            } //la coda è vuota
            Shape * tmp = array[head];    //T TMP = array[head] restituisce l'eleemtno di tipo generico contenuto in quella cella dell'array
            head= (++head % maxSize);   //perchè quando arrivo arrivo alla fine dell'array devo riportare head all'inizio dell'array
            size--; //ovviamente ho tolto un elemento quindi dceremnto il numero di elementi inseriti
            return tmp; 
        }

        friend ostream& operator<<(ostream& out, Coda_Statica &c){
            out<<"DIMENSIONE DELLA CODA = "<<c.size<<endl;
            out<<"--------------------------"<<endl;
            for(int i=c.head,count=0 ; count<c.size ; count++){
                out<<*c.array[i]<<" "<<c.array[i]<<endl;
                i= (i+1) % c.maxSize; //quando arrivo alla fine, facendo il modulo torno alla prima posizione
            }
            return out;
        }

        int get_Size(){
            return this->size;
        }
};


#endif