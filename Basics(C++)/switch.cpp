# include<iostream>
using namespace std;
int main()
 { char button;
 cout<<"input";
 cin>>button;
// if(button=='a')
// {cout<<"hello ";}
// else if(button=='b')
// {cout<<"hii ";}
// else if (button=='c')
// {cout<<"namaste ";}
// else { cout<<"nothing";}
switch(button)
{ case 'a':
cout<<"hello";
break;
case 'b':
cout<<"hii";
break;
case 'c':
cout<<"hey baby ";
break;
default :
cout<<"i am still learning";
break;}
     return 0;
 }


