#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=n;i>=1;i--){
        char c=65;
        for(int j=1;j<=n;j++){
            if(j<=i){
                cout<<c;
                c++;}
            else cout<<" ";    
        }
        c=c-2;
        for(int j=n-1;j>=1;j--){
            if(j<=n-i){
                cout<<c;
                c--;
            }
            else cout<<" ";
        }

    cout<<endl;   
    }
    return 0;
}