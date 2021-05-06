#include<iostream>
using namespace std;
int maxnumber(int a[],int n){
    int indexarr[n-1],t,o=0;
    for(int i=0;i<n-1;i++){
        indexarr[i]=0;
    }
    for(int i=1;i<n-1;i++){
        
        if((a[i-1]-a[i])==(a[i]-a[i+1])){
            indexarr[o]++;
        }
        else{
            indexarr[o]+=1;
            o++;
        }
    }
    int max=indexarr[0];
    for(int i=0;i<n-1;i++){
        if(indexarr[i]>max){
            max=indexarr[i];
        }
    }
    return max;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<(maxnumber(a,n)+1);
    return 0;
}