
// This code will work for connected as well as disconnected undirected graph

#include<bits/stdc++.h>
using namespace std;

bool checkForCycleBfs(vector<int> adj[], int vis[], int s){
    queue<pair<int,int>> q;
    q.push({s,-1});
    vis[s] = 1;

    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;

        q.pop();
        for(auto x : adj[node]){
            if(!vis[x]){
                vis[x] = 1;
                q.push({x,node});
            }
            else if(par != x) return true;
        }
    }

    return false;
}

bool isCyclic(vector<int> adj[], int vis[], int n){
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(checkForCycleBfs(adj, vis, i))  return true;
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