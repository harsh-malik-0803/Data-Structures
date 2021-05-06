#include<iostream>
using namespace std;
void towerofhanoi(int n,char sp,char ep,char hp){
    if(n==0){
        return ;
    }
    towerofhanoi(n-1,sp,hp,ep);
    cout<<"move from " <<sp<<" to "<<ep<<endl;
    towerofhanoi(n-1,hp,ep,sp);
}
int main(){
    towerofhanoi(3,'A','B','C');
}