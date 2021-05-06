#include<iostream>

using namespace std;
#include"stackusinglinked.cpp"
int main(){
    stack<char> s ;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.givesize()<<endl;

    cout<<s.isempty()<<endl;
    return 0;

}