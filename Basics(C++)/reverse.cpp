# include<iostream>
using namespace std;
int main()
{
    int n,reverse=0;
    cin>>n;
    while(n>0)
    {
        int lastdigit=n%10;
        reverse=10*reverse + lastdigit;

        n=n/10;
    }
    cout<<reverse;
    return 0;
    
}