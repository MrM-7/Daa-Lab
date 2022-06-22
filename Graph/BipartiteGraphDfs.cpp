
#include<bits/stdc++.h>
using namespace std;

bool bipartiteDfs(vector<int> adj[], int color[], int node){

    if(color[node] == -1)
        color[node] = 1;

    for(auto x: adj[node]){
        if(color[x] == -1){
            color[x] = 1 - color[node];
            if(!bipartiteDfs(adj, color, x))
                return false;
        }
        else if(color[x] == color[node])
            return false;
    }

    return true;
}

bool checkBipartite(vector<int> adj[],int n){
    int color[n+1];
    memset(color, -1, sizeof(color));

    for(int i=1; i<=n; i++){
        if(color[i] == -1){
            if(!bipartiteDfs(adj, color, i))
                return false;
        }
    }
    return true;
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

    bool result = checkBipartite(adj, n);
    if(result)
        cout<<"Bipartite Graph";
    else 
        cout<<"Not a Bipartite Graph";

    return 0;
}