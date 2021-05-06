#include<stdio.h>
bool is_sorted(int a[],int n){
	if(n==0 || n==1){
		return true ;
	}
	if (a[0]>a[1]){
		return false;
	}
	bool issmaller_sorted=is_sorted(a+1,n-1);
	return issmaller_sorted;
}
int main(){
int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
}
int t=is_sorted(a,n);
printf("%d",t);
return 0;
}