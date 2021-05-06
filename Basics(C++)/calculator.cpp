# include<iostream>
using namespace std;
int main()
{float a,b ;
char op ;
cout<<"enter the first number ";
cin>>a;
cout<<"enter the second number ";
cin>>b;

cout<<"enter the op ";

cin>>op;
switch(op)
 {
    case '+':
    cout<<" sum of two numbers is "<<a+b;
    break;
    case '-':
    cout<< a-b;
    break;
    case '*':
    cout<< a*b;
    break;
    case '/':
    cout<< a/b;
    break;
    default:
    cout<<"i am still learning ";
    break;



}
    return 0;

}