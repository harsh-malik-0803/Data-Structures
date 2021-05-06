// BST= 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1
#include<iostream>
#include<queue>
#include<cmath>
#include<iomanip>
#include<limits>
template<typename T>
class BinaryTree{
    public:
    T data;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTree(){
        delete right;
        delete left;
    }    
};
using namespace std;
BinaryTree<int>* takeinput(){
    int rootdata;
    cout<<"Enter the root data : ";
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTree<int>* root = new BinaryTree<int>(rootdata);
    BinaryTree<int>* leftchild= takeinput();
    BinaryTree<int>* rightchild= takeinput();
    root->left=leftchild;
    root->right=rightchild;
    return root;
}
void printTree(BinaryTree<int>* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);

}
BinaryTree<int>* takeinputlevelwise(){
    int rootdata;
    cout<<"Enter the root data : ";
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTree<int>* root=new BinaryTree<int>(rootdata);
    queue<BinaryTree<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        BinaryTree<int>* front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter the left child of "<<front->data<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if(leftchilddata!=-1){
            BinaryTree<int >* leftchild= new BinaryTree<int>(leftchilddata);
            front->left=leftchild;
            pendingnodes.push(leftchild); 
        }
        cout<<"Enter the right child of "<<front->data<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if(rightchilddata!=-1){
            BinaryTree<int >* rightchild= new BinaryTree<int>(rightchilddata);
            front->right=rightchild;
            pendingnodes.push(rightchild); 
        }
    }
    return root;
}// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int num_nodes(BinaryTree<int>* root){
    if(root==NULL){
        return 0;
    }
    int ans=1;
    if(root->left!=NULL){
        ans+=num_nodes(root->left);
    }
    if(root->right!=NULL){
        ans+=num_nodes(root->right);
    }
    return  ans;
}
void inorder(BinaryTree<int>* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
BinaryTree<int>* buildTree_helper(int * in ,int  * pre,int  inS,int inE,int preS,int preE){
    if(inS>inE){
        return NULL;
    }
    int rootData=pre[preS];
    int rootindex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootindex=i;
            break;
        }
    }
    int linS=inS;
    int linE=rootindex-1;
    int lpreS=preS+1;
    int lpreE=linE+lpreS-linS;
    int rinS=rootindex+1;
    int rinE=inE;
    int rpreS=lpreE+1;
    int rpreE=preE; 
    BinaryTree<int>* root=new BinaryTree<int>(rootData);
    root->left=buildTree_helper(in ,pre,linS,linE,lpreS,lpreE);
    root->right=buildTree_helper(in ,pre,rinS,rinE,rpreS,rpreE);

    return root;
}
BinaryTree<int>* buildTree(int * in ,int* pre,int size){
    return buildTree_helper(in,pre,0,size-1,0,size-1);
}
// Diameter of tree= maximum distance between any two nodes
// 1.  time complexity = O(log(n)*h) where , h=height
/*int height(BinaryTree<int>* root){
    if(root==NULL){
        return 0;
    }
    return (1+max(height(root->left),height(root->right)));
}
int Diameter(BinaryTree<int>*root){
    if(root=NULL){
        return 0;
    }
    int option1=height(root->left) + height(root->right);
    int option2= Diameter(root->left);
    int option3=Diameter(root->right);
    return max(option1+1,max(option2,option3));
}*/
// UTILITY FUNCTIONS TO TEST diameter() FUNCTION
 
// The function Compute the "height" of a tree. Height is
// the number f nodes along the longest path from the root
// node down to the farthest leaf node.
int height(BinaryTree<int>* root)
{
    // base case tree is empty
    if (root == NULL)
        return 0;
 
    // If tree is not empty then height = 1 + max of left
    // height and right heights
    return 1 + max(height(root->left), height(root->right));
}
int diameter(BinaryTree<int>* tree)
{
    // base case where tree is empty
    if (tree == NULL)
        return 0;
 
    // get the height of left and right sub-trees
    int option1 = height(tree->left)+height(tree->right);
 
    // get the diameter of left and right sub-trees
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
 
    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1
    return max(option1 + 1,max(ldiameter, rdiameter));
}
// 2. way  time complexity o(h) h= height
pair<int,int> heightdiameter(BinaryTree<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftans= heightdiameter(root->left);
    pair<int,int> rightans=heightdiameter(root->right);
    int ld=leftans.second;
    int rd=rightans.second;
    int lh=leftans.first;
    int rh=rightans.first;
    int height=max(lh,rh)+1;
    int diameter = max(lh+rh,max(ld,rd));
    pair<int,int> p;
    p.first=height;
    p.second=diameter;
    return p;
} 
BinaryTree<int>* BinaryTreeSearch(BinaryTree<int>* root,int element){
    if(root==NULL){
        return NULL;
    }
    if(root->data == element){
        return root;
    }
    if(root->data>element){
        BinaryTreeSearch(root->left,element);
    }
    else {
        BinaryTreeSearch(root->right,element);
    }
}
vector<int>* PrintInRange(BinaryTree<int>* root,int low,int high){
    if(root==NULL || root->data<low || root->data>high ){
        vector<int>* v=new vector<int>();
        v->push_back(NULL);
        return v;
    }
    if(high>root->data){
        vector<int>* v= new vector<int>();
        v->push_back(root->data);
        PrintInRange(root->right,low,high);
    }
    if(low<root->data){
        vector<int>* v= new vector<int>();
        v->push_back(root->data);
        PrintInRange(root->left,low,high);
    }
    return v;
}
int minimum(BinaryTree<int>* root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(BinaryTree<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isBST1(BinaryTree<int>* root){
    if(root==NULL){
        return true;
    }
    int lmax=maximum(root->left);
    int rmin=minimum(root->right);
    bool output=root->data>lmax && root->data<rmin && isBST1(root->left) && isBST1(root->right);
}
class isBSTreturn{
    public:
    bool isBST;
    int minimum;
    int maximum;
};
isBSTreturn isBST2(BinaryTree<int>* root){
    if(root==NULL){
        isBSTreturn output;
        output.isBST =true;
        output.minimum= INT_MAX;
        output.maximum=INT_MIN;
        return output;
    }
    isBSTreturn loutput=isBST2(root->left);
    isBSTreturn routput=isBST2(root->right);
    int minimum=min(root->data,min(loutput.minimum,routput.minimum));
    int maximum=max(root->data,max(loutput.maximum,routput.maximum));

    bool isBSTfinal= ((root->data >loutput.maximum) && root->data<=
    routput.minimum && loutput.isBST && routput.isBST);
    isBSTreturn output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBST=isBSTfinal;
    return output;
}

bool isBST3(BinaryTree<int>* root,int min=INT_MIN,int max=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data<min || root->data>max){
        return false;
    }
    bool isleftOK= isBST3(root->left,min,(root->data)-1);
    bool isrightOK= isBST3(root->right,max,(root->data)-1);
    return isleftOK && isrightOK;
}
/*BinaryTree<int>* BinaryFROMsorted_array(int arr,int si,int ei){
    if(si-ei==0){
        return NULL;
    }
    
    BinaryTree<int>* root =new BinaryTree<int>(arr[(si+ei)/2]);

    return root;
}*/
vector<int>* getRoottoNode(BinaryTree<int>* root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        vector<int>* output= new vector<int>();
        output->push_back(data);
        return output;
    }
    vector<int>* loutput=getRoottoNode(root->left,data);
    if(loutput!=NULL){
        loutput->push_back(root->data);
        return loutput;
    }
    vector<int>* routput=getRoottoNode(root->right,data);
    if(routput!=NULL){
        routput->push_back(root->data);
        return routput;
    }
    else  {
        return NULL;
    }
}

int main(){
    /*BinaryTree<int>* root=new BinaryTree<int>(1);
    BinaryTree<int>* node1=new BinaryTree<int>(2);
    BinaryTree<int>* node2=new BinaryTree<int>(3);
    root->left=node1;
    root->right=node2;*/
    BinaryTree<int>* root= takeinputlevelwise();
    
    /*int in[]={4,2,5,1,8,6,9,3,7};
    int pre[]={1,2,4,5,3,6,8,9,7};
    BinaryTree<int>* root= buildTree(in,pre,9);
    printTree(root);
    cout<<"number of nodes are : "<<num_nodes(root)<<endl;
    cout<<"inorder is : ";
    inorder(root);*/
    /*cout<<"Diameter is : ";
    cout<<diameter(root)<<endl;*/
    /*pair<int,int> p= heightdiameter(root);
    cout<<"Height : "<<p.first<<endl;
    cout<<"Diameter : "<<p.second;*/
    cout<<"Adress of index is : "<<BinaryTreeSearch(root,3);
    delete root;
    return 0;
}
