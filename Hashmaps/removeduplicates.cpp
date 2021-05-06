#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeduplicates(int *a ,int size){
    vector<int> output;
    unordered_map<int ,bool> seen;
    for(int i=0;i<size;i++){
        if(seen.count(a[i])>0){
            continue;
        }
        seen[a[i]]=true;
        output.push_back(a[i]);
    }
    return output;
}

int main(){
    int a[]={1,4,6,8,1,7,8,6};
    cout<<"Final array is : ";
    vector<int> output=removeduplicates(a,8);
    for(int i=0;i<output.size();i++){
        cout<<output.at(i)<<" ";
    }
}