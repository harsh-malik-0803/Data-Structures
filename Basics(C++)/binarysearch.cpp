#include<iostream>
using namespace std;
int binarysearch(int array[],int n,int key){
    int s=0;
    int e=n;
    while(s<=e){
        int midpoint=(s+e)/2;
        if(array[midpoint]==key)
        return midpoint;
        else if(array[midpoint]>key) 
        {e=midpoint-1;}
        else {s=midpoint+1;}
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {cin>>array[i];
    }
    int key ;
    cin>>key;
    cout<<binarysearch(array,n,key);
}