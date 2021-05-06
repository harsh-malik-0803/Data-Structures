#include<iostream>
using namespace std;
void steps_moved(int n,char S ,char D,char E){
    if(n==0){
        return;
    }
    steps_moved(n-1,S,E,D);
    cout<<"move disk "<<n<<" from "<<S<<" to "<<D<<endl;
    steps_moved(n-1,E,D,S);
}
int main(){
    int n;
    cout<<"how many you want to move : ";
    cin>>n;
    steps_moved(n,'S','D','E');
    return 0;
}