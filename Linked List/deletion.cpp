#include<iostream>
using namespace std;
#include"Node.cpp"

Node* take_input(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail= NULL;
    
    while(data!=-1){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
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

void deletition(Node*head, int index){
    int count=0;
    Node* a=head;
    while (count<index-1)
    {
        a=a->next;
        count++;
    }
    Node* temp=a->next;
    a->next=temp->next;
    delete temp;
    
}
int main(){
    Node* head=take_input();
    print(head);
    int index;
    cin>>index;
    deletition(head,2);
    print (head);
}