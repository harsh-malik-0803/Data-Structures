#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int binary=0;
    int i=0;
while(n>0){
    int x=n%2;
    binary+=x*pow(10,i);
    i++;
    n=n/2;
}
 cout<<binary;
    return 0 ;
    
}