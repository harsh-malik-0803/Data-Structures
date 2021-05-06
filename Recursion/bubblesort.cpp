#include<iostream>
using namespace std;
void bubble_sort(int n,int a[]){
    if(n==1) return ;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            int temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
    bubble_sort(n-1,a);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubble_sort(n,a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}