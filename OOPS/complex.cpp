#include<iostream>
using namespace std;
class complex_no{
    int real;
    int imaginary;
    public:
    complex_no(int real,int imaginary){
        this->real=real;
        this->imaginary=imaginary;
    }
    void print(){
        cout<<real<<"+"<<imaginary<<"i"<<endl;
    }
    void add(complex_no n2){
        this->real=this->real+n2.real;
        this->imaginary=this->imaginary+n2.imaginary;
        print();
    }

};

int main(){
    complex_no n1(1,2);
    complex_no n2(3,4);
    cout<<"Your entered no is : ";
    n1.print();
    cout<<"Your entered no is : ";
    n2.print();
    cout<<"Sum of two complex numbers are : ";
    n1.add(n2);

}