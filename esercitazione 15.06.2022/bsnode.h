#ifndef BST_NODO_H
#define BST_NODO_H
#include <iostream>
using namespace std;
#include "Shape.h"
//il nodo di un albero contiene un valore, un puntatore al figlio destro e figlio sinistro, e tranne nel caso della radice
//un puntatore al genitore quindi avremo bisogno di una chiave e 3 puntatori

template <typename T>
class BSTNode{
    BSTNode<T> * left;      //puntatore al nodo sinistro
    BSTNode<T> * right;     //puntatore al nodo destro
    BSTNode<T> * parent;    //puntatore al padre
    T key;  //valore di tipo generico
    bool verbose= false;    

    template <typename U>
    friend class BST;

    public:
        BSTNode(T key, bool verbose=true) : key(key), verbose(verbose){  //quando creo il nodo passo un valore e inizializzo il nodo
            left= nullptr;
            right= nullptr;
            parent= nullptr;
        }

        BSTNode(){          //costruttore vuoto nel caso in cui devo stampare il min o massimo dell'albero
            left= nullptr;
            right= nullptr;
            parent= nullptr;
        }

        T getValue(){           //torna il valore del nodo
            return this->key;
        }

        BSTNode<T> * getRight(BSTNode<T> * ptr){        //ritorno l'indirizzo del nodo destro
            return this->ptr->right;
        }

        BSTNode<T> * getLeft(BSTNode<T> * ptr){  //ritorno l'indirizzo del nodo sinistro
            return this->ptr->left;
        }

        BSTNode<T> * getParent(BSTNode<T> * ptr){ //ritorno l'indirizzo del nodo genitore
            return this->ptr->parent;
        }

        BSTNode<T> * setLeft(BSTNode<T> * ptr){     //setta come figlio sinistro il nodo passato
            this->left= ptr;
        }

        BSTNode<T> * setRight(BSTNode<T> * ptr){       //setta come figlio destro il nodo passato
            this->right= ptr;
        }

        void  setParent(BSTNode<T> * ptr){       //setta il genitore del nodo con ptr
            this->parent= ptr;
        }

        void setKey(T key){     //cambia il valore del nodo passatogli nella funzione
            this->key = key;    
        }

        friend std::ostream& operator<<(std::ostream& out, BSTNode<T>& node) {
		if(node.verbose)
			out << " key=" << *node.key << " - left=" << node.left << " right=" << node.right << " parent=" << node.parent;
		else
			out << "BSTNode key=" << node.key;
		return out;
	}

};






#endif