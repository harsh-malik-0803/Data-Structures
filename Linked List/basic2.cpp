#include<iostream>
using namespace std;
#include "Node.cpp"
Node* reverse_list(Node*head){
    if(head==NULL || head->next==NULL){
            return head;
        }
        Node* smallans=reverse_list(head->next);
        Node* tail=head->next;
        tail->next=head;
        head->next=NULL;
        return smallans;
}
Node* take_input(){
    int data;
    cin>>data;
    Node* head= NULL;
    Node* tail= NULL;
    while(data!=-1){
        Node* newNode=new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        else{

            tail->next= newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    /* Node* n1=new Node(1);
    Node* n2=new Node(2);
    Node* n3=new Node(3);
    Node* n4=new Node(4);
    Node* n5=new Node(5);

    Node*head=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5; */
    
    Node* head=take_input();

    print(head);
    Node* temp=reverse_list(head);
    cout<<endl;
	print(temp); 

    return 0;
}
