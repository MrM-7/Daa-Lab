#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v, char x){
    adj[u].push_back(v);

    if(x=='U' || x=='u')
        adj[v].push_back(u);
}

bool checkPath(vector<int> adj[], int u, int v){
    for(auto x: adj[u]){
        if(x == v)
            return true;
    }
    return false;
}

int main(){
    int n;
    
    cout<<"Enter total no. of vertices: ";
    cin>>n;
    vector<int> adj[n];
    
    cout<<"D : Directed graph\nU : Undirected graph\n";
    cout<<"Enter choice: ";
    char x;
    cin>>x;
    
    for(int i=0;;i++){
        cout<<"Enter edge: ";
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v,x);
        cout<<"Quit(Y/N): ";
        char ch;
        cin>>ch;
        if(ch=='Y'||ch=='y') break;
    }

    cout<<"Enter two vertices for path checking: ";
    int u, v;
    cin>>u>>v;

    if(checkPath(adj,u,v))
        cout<<"Path exists"<<endl;
    else 
        cout<<"Path doesn't exist"<<endl;

    return 0;
}