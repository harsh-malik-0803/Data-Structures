// 1 3 2 3 4 2 5 6 1 7 0 0 0 0 
#include<iostream>
#include<queue>
#include<cmath>
#include"Treenode.h"
using namespace std;

TreeNode<int>* takeinputlinewise(){
    int rootdata;
    cout<<"Enter root data : "<<endl;
    cin>>rootdata;
    TreeNode<int>* root=new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        TreeNode<int>* front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter number of childrens of "<<front->data<<endl;
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int childdata;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childdata;
            TreeNode<int>* child=new TreeNode<int>(childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}
/*TreeNode<int>* takeinput(){
    int rootdata;
    cout<<"Enter data : "<<endl;
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    int n;
    cout<<"Enter number of childrens of : "<<rootdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child=takeinput();
        root->children.push_back(child);
    }
    return root;
}*/

void printTree(TreeNode<int>* root){
    if(root==NULL){ // it is a edge case not a base case 
        return ;
    }
    // dont use base case cause it don need as it moves out of loop
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
int count_nodes(TreeNode<int>* root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=count_nodes(root->children[i]);
    }
    return ans;
}
int tree_height(TreeNode<int>* root){
    
    int height=0,maxno=0;
    for(int i=0;i<root->children.size();i++){
        height++;
        maxno=max(height,maxno);
        tree_height(root->children[i]);
    }    
    return maxno;
}
void printAtk(TreeNode<int>*root,int depth){
    if(depth==0){
        cout<<root->data<<" ";
        return ;
    }
    for(int i=0;i<root->children.size();i++){
        printAtk(root->children[i],depth-1);
    }
}
int leaf_nodes(TreeNode<int>* root){
    if(root->children.size()==0){
        return 1;
    }
    int ans =0;
    for(int i=0;i<root->children.size();i++)
    ans+=leaf_nodes(root->children[i]);
    return ans;
}
void preorder(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
        
    }
}
void postorder(TreeNode<int>*root){
    if(root!=NULL){
        for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
        cout<<root->data<<" ";

        }  
    }
    
}
// to delete   A tree 
void delete_tree(TreeNode<int>* root){
    for(int i=0;i<root->children.size();i++)
    delete_tree(root->children[i]);
    delete root;
}
int main(){
    /*TreeNode<int>* root= new TreeNode<int>(1);
    TreeNode<int>* node1= new TreeNode<int>(2);
    TreeNode<int>* node2= new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);*/
    TreeNode<int>*root=takeinputlinewise();
    printTree(root);
    cout<<"number of nodes are : " <<count_nodes(root)<<endl;
    /*int depth;
    cout<<"Enter the depth : ";
    cin>>depth;
    printAtk(root,depth);*/
    //cout<<"height of a tree is : " <<tree_height(root)<<endl;
    cout<<"number of leaf nodes are : "<<leaf_nodes(root)<<endl;
    cout<<"Preorder transversal is : " ;
    preorder(root);
    cout<<"\nPostorder transversal is : ";
    postorder(root);
}