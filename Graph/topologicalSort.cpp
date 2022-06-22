#include<bits/stdc++.h>
using namespace std;

void findTopoSort(vector<int> adj[], int vis[], stack<int> &st, int node){
    vis[node] = 1;

    for(auto x: adj[node]){
        if(!vis[x]){
            findTopoSort(adj, vis, st, x);
        }
    }

    st.push(node);  
}

vector<int> topoSort(vector<int> adj[], int vis[], int n){
    stack<int> st;
    vector<int> topo;

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            findTopoSort(adj, vis, st, i);
        }
    }
  
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
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
    }

    vector<int> result = topoSort(adj, vis, n);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}