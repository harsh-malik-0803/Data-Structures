# include<iostream>
# include<cmath>
# include<math.h>

using namespace std;
bool isprime(int num){
    for(int i=2;i<(num);i++)
    {
        if (num%i==0)
        return false;
    }
    return true;
}
int main()
{
    int a,b;
    cin>>a>>b;
    for(int j=a;j<=b;j++)
    {if(isprime(j) )
    cout<<j<<" ";
    }
    return 0;


}