#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Recursive code to check for cycle in graph
bool cycleDetection(vector<int> adj[], int s, int visited[], int parent){
    visited[s] = 1;
    bool result = false;

    for(auto x: adj[s]){
        if(visited[x] != 1){
            result = cycleDetection(adj,x,visited,s);
            if(result)  break;
        }

        else if(x != parent) 
            return true;
    }
    return result;
}

int main(){
    int n=5;
    
    cout<<"Enter total no. of vertices: ";
    cin>>n;
    vector<int> adj[n];
    
  // For loop for edges input
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
    bool result = cycleDetection(adj,src,visited,-1);


    if(result)  cout<<"-----Graph contains cycle-----\n";
    else        cout<<"-----Graph doesn't contain cycle-----\n";

    return 0;
}
