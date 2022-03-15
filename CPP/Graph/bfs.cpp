#include<bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> graph,int start,vector<bool> visited){
    queue<int> qu;
    visited[start]=true;
    qu.push(start);
    while(!qu.empty()){
        int r=qu.front();
        qu.pop();
        cout<<r<<" ";
        for(auto nbr:graph[r]){
            if(visited[nbr]==false){
                visited[nbr]=true;
                qu.push(nbr);
            }
        }
    }
}
//displaying the graph
void display(vector<vector<int>> graph){
    for(int i=0;i<graph.size();i++){
        cout<<"["<<i<<"] ==>  ";
        for(auto a:graph[i]){
            cout<<a<<"->";
        }
        cout<<"\n";
    }
}
int main(){
    int n=6;//number of nodes
    vector<vector<int>>edges={{0,1},{0,2},{1,4},{2,3},{3,5},{5,4},{4,3}}; //edges
    vector<vector<int>> graph(n,vector<int>());
    vector<bool> visited(n+1,false);
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // display(graph);
    bfs(graph,0,visited);
    cout<<"\n";
    // bfs(graph,3,visited);
    
    return 0;
}