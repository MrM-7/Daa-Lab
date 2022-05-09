#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[], int src, int n){
    queue<int> q;
    int visited[n] = {0};

    q.push(src);
    visited[src] = 1;

    while(!q.empty()){
        int u = q.front();
        cout<<u<<" ";

        for(auto x: adj[u]){
            if(visited[x] != 1){
                q.push(x);
                visited[x] = 1;
            }
        }

        q.pop();
    }
}

int main(){
    // cout<<"Enter number of vertices: ";
    // int n;
    // cin>>n;

    int n=5;   //Let

    vector<int> adj[n];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,0);

    cout<<"Enter source vertex: ";
    int src;
    cin>>src;

    bfs(adj, src, n); 
    return 0;
}
