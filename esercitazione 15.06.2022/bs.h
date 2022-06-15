#ifndef BST_H
#define BST_H
#include <iostream>
#include "bsnode.h"
using namespace std;

template <typename T>
class BST{
    BSTNode<T> * root;  //puntatore alla radice , ovvero il primo elemento

    public:
        BST(){
            root = nullptr; //appena creo l'albero la radice è vuota
        }

        bool isEmpty(){
            return root==nullptr;   //l'albero è vuoto quando root non punta a niente, in tal caso non c'è nemmeno la radice
        }

        void insert(T key){
            if(isEmpty()){                      //1 CASO  : ALBERO VUOTO -> allora creo la radice e non devo fare piu niente
                root= new BSTNode<T>(key);
                return;
            }
            cout<<key;
            insert(key,root);   //2 CASO: la radice esiste,quindi devo mettere il valore nel sottoalbero sinistro o destro rispetto la radice
        }

        void insert(T key, BSTNode<T> * ptr){   //funzione ricorsiva che scorre il sottoalbero destro e sottoalbero sinistro
            if(ptr->left == nullptr && *(ptr->key) > *key){ //se non esiste il figlio sinistro ed inoltre il valore è minore rispetto al genitore lo inserisco
                ptr->left = new BSTNode<T>(key); //creo il nodo
                ptr->left->setParent(ptr);  //setto il genitore del nodo creato
                return;
            }

            if(ptr->right == nullptr && *(ptr->key) < *key){ //stessa cosa di sopra ma nel caso in cui il valore è piu grande del genitore
                ptr->right= new BSTNode<T>(key);
                ptr->right->setParent(ptr);
                return;
            }

            //se invece l'albero è pieno dobbiamo scorrere ricorsivamente i vari sottoalberi sinistri e destri finchè non abbiamo dove creare il nodo 
            if(*(ptr->key) >= *key){
                insert(key, ptr->left); //scorro il sottoalbero sinistro
            }else   
                insert(key,ptr->right); //scorro il sottoalbero destro
        }

        void visit(BSTNode<T> * ptr){
            cout<<*ptr<<endl;   //dato un indirizzo stampa il valore del nodo
        }

        void inOrder(){
            inOrder(root);
        }

        void inOrder(BSTNode<T> * ptr){ //funzione ricorsiva, visito ricorsivamente il sottoalbero sinistro,poi la radice e poi ricorsivamente il sottoalbero destro
        //nell'esempio che ho inserito nel main allora stampera'
        //1-2-3-4-5-6-7-10-12-14-16-18
        //perchè arriva alla fine del sottoalbero sinistro,appena finisce stampa, poi torna al genitore,e poi stampa il sottoalbero destro
        //ed avviene cosi in maniera ricorsiva
            if(ptr==nullptr) return;

            inOrder(ptr->left);
            visit(ptr);
            inOrder(ptr->right);
        }

        void postOrder(){
            postOrder(root);
        }

        //postOrder: la visita parte dalla foglie  dell'albero per poi arrivare alla radice 

        void postOrder(BSTNode<T> * ptr){   //visita ricorsivamente il sottoalbero sinistro, poi destro e poi infine la radice
            if(ptr==nullptr) return;
        //arriva fino alla fine del sottoalbero sinistro, poi risale al genitore e stampa tutto il sottoalbero destro, e poi riparte
            postOrder(ptr->left);
            postOrder(ptr->right);
            visit(ptr);
        }

        void preOrder(){
            preOrder(root);
        }

        void preOrder(BSTNode<T> * ptr){    //la visita parte dalla radice per poi finire alle foglie che sono gli ultimi ad essere visitate
            if(ptr==nullptr) return;

            visit(ptr);
            preOrder(ptr->left);
            preOrder(ptr->right);
        }


        BSTNode<T> * min(){  //funzione che verrà usata nel main, quindi passerò nell'altra funzione root che sarebbe l'indirizzo della radice
            return min(root);
        }

        //adesso andiamo a cercare il minimo e massimo 
        BSTNode<T> * min(BSTNode<T> * ptr){ 
            if(ptr==nullptr) return nullptr;       //se l'indirizzo passato è nullptr allora ritorno nullptr ovvero che non esiste nessun nodo

            while(ptr->left){       //il minimo è il nodo piu piccolo, quindi è il nodo piu a sinistra, allora scorro a sinistra finchè non arrivo all'ultimo nodo a sinistra
                ptr= ptr->left; 
            }

            return ptr; //ritorno l'indirizzo di questo nodo
        }


        BSTNode<T> * max(){
            return max(root);
        }

        BSTNode<T> * max(BSTNode<T> * ptr){         //la funzione max è il contrario
            if(ptr==nullptr) return nullptr;    

            while(ptr->right){          //max è la foglia piu a destra quindi scorro a destra finch non arriva all'ultimo elemento quindi condizione!nulltrp
                ptr= ptr->right;
            }

            return ptr; //torno lindirizzo della foglia piu a destra che contiene il valore piu alto dell'albero
        }


        BSTNode<T>* search(int key){
            return search(key,root);
        }

        //la funzione search restituisce se esiste il nodo di un albero che ha un dato valore
        BSTNode<T>* search(int key, BSTNode<T> * ptr){
            if(ptr==nullptr)    //caso base
                return nullptr;    
            if(*(ptr->key) == key )    //se ho trovato allora ritorno l'indirizzo del nodo
                return ptr;

            else if(*(ptr->key) > key)         
                return search(key, (ptr->left));  //torno il nodo sinistro
            else                           
                return search(key, (ptr->right)); //torno il nodo destro

            return nullptr;  //se non ho trovato il valore allora vuol dire che devo restituire nullptr perchè il nodo non esiste
        }

        //tramite la funzione search che restituisce l'indirizzo del nodo data una chiava, posso trovare il successore di questo nodo tramite questa funzione
        BSTNode<T> * successore(BSTNode<T>* ptr){
            //1 caso: il successore di un nodo che ha un figlio destro è il minimo del sottogruppo destro
            if(ptr->right != nullptr){
                return min(ptr->right);
            }

            //2 caso : il successore di un nodo che non ha un figlio destro ed  è figlio sinistro del genitore,il successore il padre
            //l'ultimo caso invece che il successore è l'antenato di quel sottoalbero
            BSTNode<T>* y = ptr->parent;
            while( ptr != nullptr && ptr == y->right){
                ptr= y;
                y= y->parent;
            }       //se il while viene eseguito torna l'antenato che sarebbe il successore
            //se il while non viene eseguito allora vuol dire che il nodo era il figlio sinistro del genitore(CASO 2)

            return y;
        }



        BSTNode<T> * predecessore(BSTNode<T> * ptr){
            //il predecessore di un nodo che è figlio destro è il genitore
            //il predecessore di un nodo che è figlio sinistro è il massimo del sottoalbero destro
            //il predecessore di un nodo che è figlio sinistro e non ha figli è l'antenato di quel sottoalbero
            if(ptr->left !=nullptr){
                return max(ptr->left);
            }

            BSTNode<T> * y= ptr->parent;
            while(ptr!=nullptr && ptr == y->left){
                ptr= y;
                y= y->parent;
            }
            
            return y;
        }


        //cancellazione:
        //1: la chiave da cancellare si trova in una foglia
        //2: la chiave da cancellare si trova in un nodo con un solo figlio (collegare l'unico figlio al genitore ed eliminare il nodo)
        //3: la chiave da vancellare si trovo in un nodo con due figli ()


        BSTNode<T> * remove(BSTNode<T> * node){
            //CASO 1 : LA CHIAVE DA CANCELLARE SI TROVA IN UNA FOGLIA
            if(node->left == nullptr && node->right == nullptr){
                if(node->parent->left == node)
                    node->parent->left=nullptr;
                else    
                    node->parent->right=nullptr;
                
                return node;
            }
            
            //CASO 2: La chiave da cancellare si trova in un nodo con un solo figlio
            if(node->right != nullptr && node->left== nullptr){ //se ha solo un figlio ed è quello destro
                node->right->parent = node->parent; //collego il figlio con il genitore del nodo

                if(node->parent->right == node){ //se nodo è il figlio destro del genitore
                    node->parent->right= node->right;   //collego il genitore con il figlio
                }
                else    
                    node->parent->left= node->right;        //collego il genitore con il figlio

                return node;
            }
            if(node->right == nullptr && node->left!= nullptr){ //se ha solo un figlio ed è quello sinistro
                node->left->parent = node->parent; //collego il figlio con il genitore del nodo

                if(node->parent->right == node){ //se nodo è il figlio destro del genitore
                    node->parent->right= node->left;   //collego il genitore con il figlio
                }
                else    
                    node->parent->left= node->left;        //collego il genitore con il figlio

                return node;
            }

            return nullptr; //nel caso in cui non siamo in questi due casi
        }

        void deleteNode(BSTNode<T> *ptr){
            delete ptr;
        }

        BSTNode<T> * remove(int key){
            BSTNode<T>* node= this->search(key); //search torna l'indirizzo del nodo se esiste se no nullptr
            if(node==nullptr) return nullptr;

            BSTNode<T> * toDelete= this->remove(node);
            if(toDelete!=nullptr)
                return toDelete;


            //se è nullptr allora siamo nel 3 caso: ovvero il nodo da eliminare ha due figli
            //per mantenere la struttura, cerco il successore e sostituisco il contenuto del successore con il nodo da eliminare
            //il successore è la foglia sinistra, allora cosi posso richiamare la remove del primo e secondo caso
            BSTNode<T> * next= this->successore(node);
            T valore;
            valore = next->getValue();
            next->key = node->key;
            node->key= valore;  //swap dei due valori
            //mantengo la mia struttura dati di ricerca bilanciata, nel caso in cui il nodo ha due figli, allora scambio il valore del nodo con il valore del successore del nodo
            //che sarà l'elemento a sinistra rispetto il nodo, e poi richiamo la funzione remove per andarlo a cancellare
            


            toDelete= remove(next); //to delete torna il nodo da eliminare
            return toDelete;
        }


};

#endif