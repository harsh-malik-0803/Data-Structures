#include<iostream>
#include<climits>
using namespace std;
template<typename T> 
class Node{
    public:
    Node<T> * next;
    T data;

    
    Node(T data){
        this->data=data;
        next=NULL;
    }
};
template<typename T>
class stack{
    Node<T>* head;
    int size;
    public:
    stack(){
        head=NULL;
        size==0;
    }
    int givesize(){
        return size;
    }
    bool isempty(){
        if(size==0){
            return true;
        }
        return false;
    }
    void push(T element){
        Node<T>* newnode=new Node<T>(element);
        newnode->next=head;
        head=newnode;
        size++;
    }
    
    T pop(){
        if(size==0){
            cout<<"stack is already empty"<<endl;
            return INT_MIN;
        }
        T ans=head->data;
        Node<T>* ptr=head;
        head=head->next;
        size--;
        delete ptr;
        return ans;
    }
    T top(){
        if(size==0){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        return head->data;
    }
};
