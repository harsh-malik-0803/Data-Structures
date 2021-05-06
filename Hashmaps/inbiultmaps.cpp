#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> ourmap;
    // to map , insert element
   /* pair<string,int> p("abc",1);
    ourmap.insert(p);
    ourmap["abc"]=1;

    //find or access
    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("abc")<<endl;
    //cout<<ourmap.at("ghi")<<endl;  // if not present then show error ..
    //cout<<ourmap["ghi"]<<endl;  // if not present then map that to 0..

    // check presence
    if(ourmap.count("ghi")>0){
        cout<<"Element is present "<<endl;
    }

    // size
    cout<<ourmap.size()<<endl;

    // erase 
    ourmap.erase("ghi");*/
    ourmap["abc"]=1;
    ourmap["abc1"]=1;
    ourmap["abc2"]=1;
    ourmap["abc3"]=1;
    ourmap["abc4"]=1;
    ourmap["abc5"]=1;
    ourmap["abc6"]=1;

    unordered_map<string,int> :: iterator it=ourmap.begin();
    while(it !=ourmap.end()){
        cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;
        it++;
    }
    vector<int> v;
    
    
    for(int j=0;j<5;j++){
        v.push_back(rand());
    }
    vector<int>:: iterator it1;
    it1=v.begin();
    while(it1!= v.end()){
        cout<<*it1<<endl;
        it1++;
    }
// iterator uses 
unordered_map<string,int> :: iterator it2=ourmap.find("abc");
//ourmap.erase(it2);  // deletes it2 element
// ourmap.erase(it2, it2 + 4 ); // deletes element from it2 to it2+4

}