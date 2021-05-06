// armstrong number - is a number whose sum of cube of its digit 
// is the same number . eg : 153.

# include<iostream>
# include<math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int originaln=n;
    while(n>0){
        int lastdigit=n%10;
        sum+= pow(lastdigit,3);
        n=n/10;
    }
    if (sum==originaln)
    cout<<"armstrong ";
    else
    cout<<"not armstrong";

    return 0;
}