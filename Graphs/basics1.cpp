#include<iostream>
#include<queue>
using namespace std;
void printDFS(int**edges,int n,int sv,bool *visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            printDFS(edges,n,i,visited);
        }
    }
}
void BFS(int **edges,int n,int sv,bool*visited){
    queue<int> pendingvertices;
    
    /*bool*visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }*/
    pendingvertices.push(sv);
    visited[sv]=1;
    while(!pendingvertices.empty()){
        int currentvertex=pendingvertices.front();
        pendingvertices.pop();
        cout<<currentvertex<<endl;
        for(int i=0;i<n;i++){
            if(i==currentvertex){
                continue;
            }
            if(!visited[i] && edges[currentvertex][i]==1){
                pendingvertices.push(i);
                visited[i]=true;
            }

        }
    }
}
// we use this function to print 2 or more independent graphs that are 
// not interconnected
void BFS(int **edges ,int n){
    bool*visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            BFS(edges,n,i,visited);
        }
    }    
    delete [] visited;    
}
void DFS(int **edges ,int n){
    bool*visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printDFS(edges,n,i,visited);
        }
    }    
    delete [] visited;    
}
int main(){
    int n; // vertices
    int e; // edges
    cin>>n>>e;

    int ** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    cout<<"DFS"<<endl;
    DFS(edges,n);

    cout<<"BFS"<<endl;
    BFS(edges,n);

}