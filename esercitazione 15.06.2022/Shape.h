#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

class Shape{
    protected:

    double area;

    public:

        Shape(double area=0) : area(area){}

        virtual double getArea()=0;

        virtual ostream& print(ostream &out){
            return out<<"FORMA : ";
        }

        bool operator<(Shape &s){
            return this->area < s.area;
        }

        bool operator>(Shape &s){
            return this->area > s.area;
        }

        bool operator=(Shape &s){
            return this->area= s.area;
        }

          bool operator<=(Shape &s){
            return this->area <= s.area;
        }

        bool operator>=(Shape &s){
            return this->area >= s.area;
        }

         bool operator<(int a){
            return this->area < a;
        }

        bool operator>(int a){
            return this->area >a;
        }

        bool operator=(int a){
            return this->area= a;
        }

          bool operator<=(int a){
            return this->area <= a;
        }

        bool operator>=(int a){
            return this->area >= a;
        }

        bool operator==(int a){
            return this->area==a;
        }
};

ostream& operator<<(ostream &out, Shape& o){
    return o.print(out);
}


class Rectangle : public Shape{
    private:
        double a;
        double b;

    public:
        Rectangle(double a, double b) : a(a) , b(b) {
            area= a*b;
        }

        double getArea(){
            return area;
        }

    ostream& print(ostream &out){
       return out<<"AREA "<<getArea();
    }
};  

class Circle : public Shape{
    private:
        int r;

    public:
        Circle(int r) : r(r) {
            area= r*r*3,14;
        }

        double getArea(){
            return area;
        }

         ostream& print(ostream &out){
       return out<<"AREA "<<getArea();
    }
};  



class Triangle : public Shape{
    private:
        double a;
        double b;

    public:
        Triangle(double a,double b) : a(a), b(b) {
            area=(a*b)/2;
        }

        double getArea(){
            return (a*b)/2;
        }

         ostream& print(ostream &out){
       return out<<"AREA "<<getArea();

    }
        
};  

#endif