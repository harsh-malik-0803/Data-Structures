#include<iostream>
using namespace std;
void merge_array(int a[],int si,int mi,int ei){
    int n1=mi-si+1;
    int n2=ei-mi;
    int a1[n1];
    for(int i=0;i<n1;i++){
        a1[i]=a[i+si];
    }
    int a2[n2];
    for(int i=0;i<n2;i++){
        a2[i]=a[i+mi+1];
    }
    int i=0;
    int j=0;
    int k=si;
    while(i<n1 && j<n2){
       if(a1[i]<a2[j]){
         a[k]=a1[i];
         i++;
         k++;
       } 
       else {
           a[k]=a2[j];
           k++;
           j++;
       }

    }
    while(i<n1){
        a[k]=a1[i];
        k++;
        i++;    }
    while(j<n2){
        a[k]=a2[j];
        k++;
        j++;    }

}
void merge_sort (int a[],int si,int ei){
    if(si>=ei){
        return ;
    }
    else {
    	int mi=(si+ei)/2;
    merge_sort(a,si,mi);
    merge_sort(a,mi+1,ei);
    merge_array(a,si,mi,ei);
	}
    
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
   return 0; 
}
