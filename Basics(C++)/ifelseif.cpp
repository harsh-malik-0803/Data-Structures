#include<iostream>
using namespace std;
int main()
{ 
    cout<<"enter the three numbers ";
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b){
        if(a>c)
        {cout<<"a is the largest ";}
        else {cout<<"c is the largest ";}}
    else  
    {
        if (b>c){
            cout<<"b is the largest ";}
            else 
           { cout<<"c is the largest ";
        }
    }
    return 0;
}
