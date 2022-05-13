
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
    int n=5;
    
    vector<int> adj[n];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
    addEdge(adj,3,4);
    
    int visited[n]={0};
    dfs(adj,0,visited);
}
