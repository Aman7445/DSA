#include <bits/stdc++.h>

using namespace std;
//tree using adjacent list
int main()
{
    int n;
    cin >> n;
    vector<int> *adj = new vector<int>[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << adj[1].size() << "\n";
    return 0;
}
//input format
// 5 no of nodes
// 1 2 1->2
// 1 3 1->3
// 2 4 2->4
// 3 5 3->5