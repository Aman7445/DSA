#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> topoSort;

//directional weighted graph 
void addEdge(int u,int v,int wgt){
    graph[u].push_back(make_pair(v,wgt));

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
//bfs topological sorting

void topoSorting(int n){
    queue<int> qu;
    vector<int> indegree(n,0);
    for(auto x:graph){
        if(x.size()!=0){
            for(auto a:x){
                indegree[a.first]++;
            }
        }
    }
    for(int j=0;j<n;j++){
        if(indegree[j]==0) qu.push(j);
    }
    while(!qu.empty()){
        int t=qu.front();
        qu.pop();
        topoSort.push_back(t);
        for(auto x:graph[t]){
            indegree[x.first]--;
            if(indegree[x.first]==0) qu.push(x.first);
        }
    }

}
int main(){
    int n=6;
    graph.resize(n);
    int source=0;
    addEdge(0,1,2);
    addEdge(0,4,1);
    addEdge(1,2,3);
    addEdge(2,3,6);
    addEdge(5,3,1);
    addEdge(4,5,4);
    addEdge(4,2,2);
    // Display();
    vector<int> dis(n,INT_MAX);
    dis[source]=0;
    topoSorting(n);
    for(auto nt:topoSort){
        for(auto a:graph[nt]){
            if(dis[a.first]>dis[nt]+a.second){
                dis[a.first]=dis[nt]+a.second;
            }
        }
    }
    for(auto an:dis){
        cout<<an<<" ";
    }
}