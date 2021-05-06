#include<iostream>
using namespace std;
int index(int a[],int n,int key,int i){
    if(i==n){
        return -1;
    }
    if(a[i]==key){
        return i;
    }
    return index(a,n,key,i+1);
}
int main()
{
    int n;
     cin>>n;
     int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<index(a,n,key,0);
    return 0;
}