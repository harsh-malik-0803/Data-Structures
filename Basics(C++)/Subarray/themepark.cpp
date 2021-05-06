#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>n;
    }
    if (n==1){
        cout<<"1";
        return 0;
    }
    int count=0,mx=a[0],i;
    for(i=0;i<n-1;i++){
        
        if(a[i]>a[i+1] && a[i]>mx){
            count++;
        }
        mx=max(mx,a[i]);
    }
    if(a[n-1]>mx){
        count++;}

    cout<<count;
    return 0;
}