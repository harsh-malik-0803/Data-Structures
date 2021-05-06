#include<iostream>
#include<stack>
#include<string>
using namespace std;
void reverse_usingstack(string s){
    stack <string> st;
    int i=0;
    for(int i=0;i<s.length();i++){
        string word="";
        while(i<s.length() && s[i]!=' '){
            word=word+s[i];
            i++;
        }
        st.push(word);

    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();

    }
}
int main(){
    string s="my name is harsh malik";
    reverse_usingstack(s);
}