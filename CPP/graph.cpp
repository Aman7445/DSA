#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> graph;

//weighted graph 
void addEdge(int u,int v,int wgt){
    graph[u].push_back(make_pair(v,wgt));
    graph[v].push_back(make_pair(u,wgt));

}
void Display(){
    for(auto i: graph){
        if(i.size()==0){
            cout<<"Empty";
        }
        for(auto j :i){
            cout<<"{ "<<j.first<<", "<<j.second<<" }";
        }
        cout<<"\n";
    }
    
}
int main(){
    int v,e;
    cin>>v>>e;
    graph.resize(v+1);
    while(e--){
        int u,v,wgt;
        cin>>u>>v>>wgt;
        addEdge(u,v,wgt);
    }
    Display();
}
//input format
// 6 7  no of vertices and edges
// 1 2 1
// 2 4 1
// 2 3 0
// 1 3 0
// 3 5 1
// 4 5 0
// 3 4 1

//output format
// empty //0 vertex
// {2, 1} {3, 0} //1 vertex
// {1, 1} {4, 1} {3, 0} //2 vertex
// {2, 0} {1, 0} {5, 1} {4, 1} //3 vertex
// {2, 1} {5, 0} {3, 1} //4 vertex
// {3, 1} { 4, 0 }//5 vertex