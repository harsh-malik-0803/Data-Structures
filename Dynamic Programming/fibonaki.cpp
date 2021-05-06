#include<iostream>
using namespace std;
int fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int memoisation(int n,int* ans){
    if(n==0 || n==1){
        ans[n]=n;
        return n;
    }
    if(ans[n-1]==0)
    ans[n-1]= memoisation(n-1,ans);
    if(ans[n-2]==0){
        ans[n-2]= memoisation(n-2,ans);
    }
    return ans[n-1]+ ans[n-2];
}
int memoisation(int n){
    int * ans=new int[n+1];
    for(int i=0;i<=n;i++)
    ans[i]=0;
    return memoisation(n,ans);
}

int DynamicProg(int n){
    int * ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=ans[i-2]+ans[i-1];
    }
    return ans[n];
}

int main(){
    cout<<"Nth term of fibbonacci is : "<<DynamicProg(6);
}