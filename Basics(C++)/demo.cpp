#include<iostream>
#include<cmath>
using namespace std;
int binary (int n){
    int sum=0,i=0;
    while(n!=0){
        int r=n%2;
        sum=sum+r*pow(10,i);
        n/=2;
        i++;
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    cout<<binary(n);
    return 0;
}