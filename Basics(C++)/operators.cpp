// && - and
// || - or 
// ! -  not

#include<iostream>
using namespace std;
int main()
{
    int i=10,j=20,k;
        //10    //9   //19 //9  //19   //10   //18
    int k=i-- - i++ + --j + --i - j-- + ++i - j++;
    
    cout<<i<<endl; //10 
    cout<<j<<endl; //19
    return 0;

}

