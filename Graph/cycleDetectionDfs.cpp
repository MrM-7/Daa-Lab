
// This code will work for connected as well as disconnected undirected graph

#include<bits/stdc++.h>
using namespace std;

bool checkForCycleDfs(vector<int> adj[], int vis[], int node, int parent){
    vis[node] = 1;
    for(auto x: adj[node]){
        if(!vis[x]){
            if(checkForCycleDfs(adj, vis, x, node)) return true;
        }
        else if(x != parent) return true;
    }

    return false;
}

bool isCyclic(vector<int> adj[], int vis[], int n){
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(checkForCycleDfs(adj, vis, i, -1))  return true;
        }
    }
    return false;
}

int main(){
    cout<<"Enter number of nodes and edges: ";
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];
    int vis[n+1]={0};

    cout<<"Enter edges\n";
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool result = isCyclic(adj, vis, n);
    if(result)
        cout<<"Cyclic Graph!!";
    else 
        cout<<"Not a Cyclic Graph!!";

    return 0;
}