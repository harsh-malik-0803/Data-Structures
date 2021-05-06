#include<iostream>
#include<cmath>
using namespace std;             // total subsequences = 2^n -1
int main(){
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i;j<n;j++){
            count+=a[j];
            cout<<count;
            if(j<n-1){
                cout<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}