#include<iostream>
using namespace std;
#include "student.cpp"
int main(){
    student s1;
    student *s2=new student ;

    s1.setage(20,123);
    s2-> setage(24,123);
    s1.display();
    s2->display();
}