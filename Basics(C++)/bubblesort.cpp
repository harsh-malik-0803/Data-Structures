#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"ENter the size of array : ";
    cin>>n;
    int array[n];
    cout<<"Enter elements of array : \n";
    for(int i=0; i<n;i++){
        cin>>array[i];
    }

    // code for sorting 
    for (int i=0; i<(n-1);i++){
        for(int j=0 ;j<n-1-i;j++){
            if(array[j]>array[j+1]){
            int temp = array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
            }
        }

    }
    cout<<"Sorted array is : ";
    for(int i=0 ; i<n; i++){
    cout<<array[i]<<" ";}
    return 0;
}