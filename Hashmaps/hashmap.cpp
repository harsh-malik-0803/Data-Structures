#include<iostream>
#include<string>
using namespace std;
template<typename T>
class MapNode{
    public:
    string key;
    T value;
    MapNode* next;
    MapNode(string key,T value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~MapNode(){
        delete next;
    }
};
template<typename V>
class ourmap{
    MapNode<V>** buckets;
    int count;
    int numbuckets;
    public:
    ourmap(){
        count=0;
        numbuckets=5;
        buckets=new MapNode<V>*[numbuckets];
        for(int i=0;i<numbuckets;i++){
            buckets[i]=NULL;
        }
    }
    ~ourmap(){
        for(int i=0;i<numbuckets;i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    // to write size
    int size(){
        return count;
    }
    V getvalue(string key){
        int bucketindex=getbucketindex(key);
        MapNode<V>* head= buckets[bucketindex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }
    private:
    int getbucketindex(string key){
        int hashcode=0;
        int currcoeff=1;
        for(int i=key.length()-1;i>=0;i--){
            hashcode+=key[i]*currcoeff;
            hashcode=hashcode% numbuckets;
            currcoeff*=37;
            currcoeff=currcoeff%numbuckets;
        }
        return hashcode % numbuckets;
    }
    void rehash(){
        MapNode<V>** temp= buckets;
        buckets= new MapNode<V>*[2*numbuckets];
        for(int i=0;i<2*numbuckets;i++){
            buckets[i]=NULL;
        }
        int oldbucket=numbuckets;
        numbuckets*=2;
        count=0;
        for(int i=0;i<oldbucket;i++){
            MapNode<V>* head= temp[i];
            while(head!=NULL){
                string key=head->key;
                V value = head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i<oldbucket;i++){
            MapNode<V>* head=temp[i];
            delete head;
        }
        delete [] temp;
    }
    public:
    void insert(string key , V value){
        int bucketindex= getbucketindex(key);
        MapNode<V>* head= buckets[bucketindex];
        while(head!=NULL){
            if(head->key==key)
            {
                head->value=value;
                return;
            }
            head=head->next;
        }
        head=buckets[bucketindex];
        MapNode<V>* node =new MapNode<V>(key,value);
        node->next=head;
        buckets[bucketindex]=node;
        count++;
        double loadfactor = (1.0* count)/numbuckets;
        if(loadfactor>0.7){
            rehash();
        }
    }
    V remove(string key){
        int bucketindex=getbucketindex(key);
        MapNode<V>* head=buckets[bucketindex];
        MapNode<V>* prev=NULL;
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    buckets[bucketindex]=head->next;
                }
                else{
                    prev->next==head->next;
                }
                V value=head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }
    double getloadfactor(){
        return (1.0*count)/numbuckets;
    }
};