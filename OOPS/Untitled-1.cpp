#include <iostream>
#include<string >
using namespace std;
class student{
    public : 
    int age ;
    private: 
    int rollno ;
    public: 
    void display(){
        cout<<age <<" "<<rollno;
    }

};
int main(){
    student s1;
    s1.name="harsh malik";
    s1.rollno=12012014;
    cout<<s1.display();
    student * s2=new student;
    s2 -> name=" ritesh ";
    s2 -> rollno=12012083;
    cout<<"name " << s1.name<<endl<<" roll no" <<s1.rollno;
    cout<<"name " <<(*s2).name<<endl<<" roll no "<<(*s2).rollno; 
}