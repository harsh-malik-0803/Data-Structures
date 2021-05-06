#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"enter two numbers between which you want to find prime number -";
    cin>>a>>b;
    int i,r;

    for (int r=a;r<=b;r++)
    {for(i=2;i<r;i++)
    {
        if(r%i==0)
        break ;
    }
        if (r==i)
       { cout<<r<<"  ";
       }
    
        
       
    }

    return 0;
}