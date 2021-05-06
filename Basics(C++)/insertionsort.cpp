#include<iostream>
using namespace std;

void insertionSort(int * arr,int n){
    for(int i=0;i<n;i++){
        int cnum=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>cnum){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=cnum;
    }
}
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

    insertionSort(array,n);
    cout<<"Sorted array is : ";
    for(int i=0 ; i<n; i++){
    cout<<array[i]<<" ";}
    return 0;
}
