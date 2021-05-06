#include<iostream>
using namespace std;
int main()
{int date;
int pocketmoney=2900;
    cin>>date;
    for(date=1;date<=30;date++)
    { if(date%2==0)
    {continue;}
    if (pocketmoney<=0)
    {break;}
    cout<<"go out today\n"; 
    pocketmoney=pocketmoney-300;}
    return 0;
}