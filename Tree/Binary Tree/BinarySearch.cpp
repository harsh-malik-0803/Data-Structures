#include<iostream>
using namespace std;
template<typename T>
class BinaryTree{
    public:
    T data;
    BinaryTree * left;
    BinaryTree * right;
    BinaryTree(int data){
        this->data=data;
        right=NULL;
        left=NULL;
    }
    ~BinaryTree(){
        delete left ;
        delete right;

    }
};
class BST{
    BinaryTree<int>* root;
    public:
    BST(){
        root=NULL;
    }
    ~BST(){
        delete root;
    }
    private:
    bool hasData(int data,BinaryTree<int>* root){
       if(root==NULL){
            return false;
        }
        if(root->data==data){
            return true;
        }
        else if(data <root->data){
            return hasData(data,root->left);
        }
        else {
            return hasData(data,root->right);
        }
    }
    public:
    bool hasData(int data){
        return hasData(data,root);   
    }
    private:
    BinaryTree<int>* insert(BinaryTree<int>* root, int data){
        if(root==NULL){
           BinaryTree<int>* newTree=new BinaryTree<int>(data);
           return newTree; 
        }
        else if(root->data<data){
            root->right=insert(root->right,data);
        }
        else {
            root->left=insert(root->left,data);
        }
        return root;
    }
    public:
    
};