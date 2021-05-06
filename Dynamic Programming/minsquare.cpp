#include<iostream>
#include<cmath>
using namespace std;
int minSteps(int n){
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    int t=sqrt(n);
    return minSteps(n-t*t)+1;
}
int main(){
    int n;
    cin>>n;
    cout<<"recursion : "<<minSteps(n)<<endl;
}