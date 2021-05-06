#include<iostream>
using namespace std;
int main()
{ int n;
cin>>n;
int r;
for(r=2;r<n;r++)
{
    if (n%r==0)
    {cout<<"not prime";
    break;}
}
if (r==n)
{cout<<"prime";}

    return 0;
}