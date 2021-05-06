#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
int minSteps(int n){
    if(n==1){
        return 0;
    }
    int x=minSteps(n-1);
    int y=INT_MAX,z=INT_MAX;
    if(n%2==0){
        y=minSteps(n/2);
    }
    if(n%3==0){
        z=minSteps(n/3);
    }
    return min(x,min(y,z))+1;
}
int minSteps_better(int n,int *ans){
    // a[i] denotes min steps to reduce i to 1..
    if(n==1){
        ans[n]=0;
        return ans[n];
    }
    if(ans[n-1]==-1){
        ans[n-1]=minSteps_better(n-1,ans);
    }
    int y=INT_MAX,z=INT_MAX;
    if(n%2==0){
        if(ans[n/2]==-1){
            y=minSteps_better(n/2,ans);
        }
        y=ans[n/2];
    }
    if(n%3==0){
        if(ans[n/3]==-1){
            ans[n/3]=minSteps_better(n/3,ans);
        }
        z=ans[n/3];
    }
    return min(ans[n-1],min(y,z))+1;
}
int memoisation(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return minSteps_better(n,ans);
}

//dynamic approach
int minSteps_dynamic(int n){
    int *ans=new int[n+1];
    ans[1]=0;
    int y=INT_MAX;
    int z=INT_MAX;
    for(int i=2;i<=n;i++){
        if(n%2==0){
            y=ans[n/2];

        }
        if(n%3==0){
            z=ans[n/3];
        }
        ans[n]=min(ans[n-1],min(y,z))+1;
    }
    return ans[n];
}
int main(){
    int n;
    cin>>n;
    /*cout<<"Minimum number of steps in recursion are : "<<minSteps(n)<<endl;*/
    /*cout<<"Minimum number of steps in memoisation are : "<<memoisation(n)<<endl;*/
    cout<<"Minimum number of steps in DP are : "<<minSteps_dynamic(n)<<endl;
}