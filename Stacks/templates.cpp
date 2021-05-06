#include<iostream>
using namespace std;
#include"classtemplate.cpp"
int main(){
    Pair<Pair <int,char>,double> p1;
    p1.setY(10.456);

    Pair<int ,char> p2;
    p2.setX(10);
    p2.setY('c');
    p1.setX(p2);
    cout<<p1.getX().getX() <<" "<<p1.getX().getY()<<" " <<p1.getY()<<endl;
}