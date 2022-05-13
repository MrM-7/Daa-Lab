#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[], int s, int visited[]){
    cout<<s<<" ";
    
    visited[s] = 1;
    
    for(auto x : adj[s]){
        if(visited[x] != 1){
            dfs(adj,x,visited);
        }
    }
}

int main(){
    int n;
    
    cout<<"Enter total no. of vertices: ";
    cin>>n;
    vector<int> adj[n];
    
    for(int i=0;;i++){
        cout<<"Enter edge: ";
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
        cout<<"Quit(Y/N): ";
        char ch;
        cin>>ch;
        if(ch=='Y'||ch=='y') break;
    }
    
    
    cout<<"Enter source vertex: ";
    int src;
    cin>>src;
    
    int visited[n]={0};
    cout<<"DFS: ";
    dfs(adj,src,visited);
}
