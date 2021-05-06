#include<iostream>
using namespace std;
#include"Node.cpp"

int main(){
   /* Node n1(1);
    Node* head=&n1;
    Node n2(2);
    Node n3(3);
    Node n4(4);

    n1.next= &n2;
    n2.next= &n3;
    n3.next= &n4;
    cout<< n4.next -> data<<endl;  */

    // to create dynamically
    Node* n1=new Node(11);
    Node* n2= new Node(12);
    Node* n3= new Node(13);
    n1->next=n2;
    n2->next=n3;

    cout<< 
}