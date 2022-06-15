#include "codadin.h"
#include "Shape.h"
#include "codadin.h"
#include "bs.h"
#define N 10



int main(){
    Coda_Statica re(N);
    Coda_Statica tri(N);
    Coda_Statica ce(N);

    for(int i=0;i<N; i++){
        switch(rand()%3){
            case 0:
                {
                re.enqueue(new Rectangle(rand()%30, rand()%30));
                break;
                }
            case 1:
                {
                    tri.enqueue(new Triangle(rand()%20, rand()%20));
                    break;
                }
            case 2:
                {
                    ce.enqueue(new Circle(rand()%10));
                    break;
                }
            case 3:
                {

                    break;
             }
        }
    }
    cout<<re<<endl;
    cout<<tri<<endl;
    cout<<ce<<endl;
    


    BST<Shape*> albero;
    while(re.get_Size() > 0){
        albero.insert(re.dequeue());
    }
    while(tri.get_Size() > 0){
        albero.insert(tri.dequeue());
    } while(ce.get_Size() > 0){
        albero.insert(ce.dequeue());
    }


    albero.preOrder();
    int valore=10;
    int i=0;
    while(i!=valore){
        albero.remove(i);
        i++;
    }
    cout<<endl<<endl<<endl;
    albero.preOrder();
}
