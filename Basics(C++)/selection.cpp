#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    int i, j, min_idx;  
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (array[j] < array[min_idx]) 
            min_idx = j;  
        int term=array[min_idx];
        array[min_idx]=array[i];
        array[i]=term;
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}