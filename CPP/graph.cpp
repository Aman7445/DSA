#include <bits/stdc++.h>

std::vector<std::vector<std::pair<int, int>>> graph; //vector of vector of pair where pair represents edge and vertex

std::vector<std::vector<int>> graph2;
//with weight
//for without weight use wt=0 for all edges
void addEdge(int u, int v, bool bidirect = true, int wt = 0)
{
    graph[u].push_back(std::make_pair(v, wt));
    if (bidirect)
    {
        graph[v].push_back(std::make_pair(u, wt));
    }
}
//without weight
void addEdge2(int u, int v, bool bidirect = true)
{
    graph2[u].push_back(v);
    if (bidirect)
    {
        graph2[v].push_back(u);
    }
}
void bfs(int src, int vertices)
{
    std::queue<int> que;
    std::vector<bool> visited(vertices, false);
    que.push(src);
    visited[src] = true;
    while (!que.empty())
    {
        int CurrentNode = que.front();
        que.pop();
        std::cout << CurrentNode << " ";
        for (auto neighbour : graph[CurrentNode]) //neighbour is pair
        {
            if (not visited[neighbour.first])
            {
                que.push(neighbour.first);
                visited[neighbour.first] = true;
            }
        }
    }
}
void Display()
{
    for (auto i : graph)
    {
        if (i.size() == 0)
        {
            std::cout << "empty ";
        }

        for (auto j : i)
        {
            std::cout << "{" << j.first << " , " << j.second << "}";
        }
        std::cout << "\n";
    }
}
void Display2()
{
    for (auto i : graph2)
    {
        if (i.size() == 0)
        {
            std::cout << "empty"
                      << " ";
        }
        for (auto j : i)
        {
            std::cout << "{" << j << "}";
        }
        std::cout << "\n";
    }
}

int main()
{
    int vertices, edges;
    std::cin >> vertices >> edges;
    graph2.resize(vertices); //giving the size of the graph
    while (edges--)
    {
        int u, v, wt;
        std::cin >> u >> v;
        // addEdge(u, v, true, wt);
        addEdge2(u, v, true);
    }
    Display2();
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