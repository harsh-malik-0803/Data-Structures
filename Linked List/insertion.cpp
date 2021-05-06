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

void insert(Node* head, int data ,int index){
    Node* newNode=new Node(data);
    Node* temp=head;
    int count=0;
    while(count<index-1){
        temp=temp->next;
        count++;
    }
    Node* a =temp->next;
    temp->next=newNode;
    newNode->next=a;

}
void recursion_insert(Node* head,int data, int index){
    Node* newNode=new Node(data);
    if(head==NULL){
        return ;
    }
    else if (index==1){
        Node* temp= head->next;
        head->next=newNode;
    
        newNode->next=temp;
    }
    else{
        recursion_insert(head->next,data,index-1);
    }
}
int main(){
    Node* head=take_input();

    print(head);
    int data,index;
    cin>>index;
    cin>>data;
    recursion_insert(head,data,index);
    print(head);
}