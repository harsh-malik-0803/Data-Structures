#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int target ;
    cin>>target;
    bool found = false;
    int r=0,c=m-1;
    while(r<n and c>=0){
        if(a[r][c]==target)
        {found=true;
        break;}
        if(a[r][c]>target){
            c--;
        }
        else {r++;}
    }
    if(found){
        cout<<"element is found  ";
    }
    else cout<<"element doesnt exist in given matrix";
    return 0;

}