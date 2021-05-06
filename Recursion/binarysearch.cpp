#include<iostream>
using namespace std;
int binary_search(int n,int a[],int key,int si,int ei){
    int mid=si+ei/2; 
    if(a[mid]==key){
        return mid;
    }
    else if(key>a[mid]){
        binary_search(n/2,a,key,mid+1,ei);
    }
    else{
        if(n%2==0)
        binary_search(n/2-1,a,key,si,mid-1);
        else binary_search(n/2,a,key,si,mid-1);
    }
    return -1;
}
int main(){
    int n,key;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>key;
    cout<<binary_search(n,a,key,0,n-1);
}