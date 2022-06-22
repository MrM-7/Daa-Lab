#include<bits/stdc++.h>
using namespace std;

void shortestPath(vector<int> adj[], int n, int src){
    int dist[n];
    for(int i=0; i<n; i++) dist[i] = INT_MAX;

    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto x: adj[node]){
            if(dist[node] + 1 < dist[x]){
                dist[x] = dist[node]+1;
                q.push(x);
            }
        }
    }

    for(int i=0; i<n; i++)
        cout<<dist[i]<<" ";
}

int main(){
    cout<<"Enter number of nodes and edges: ";
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];

    cout<<"Enter edges\n";
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    shortestPath(adj, n, 1);

    return 0;
}