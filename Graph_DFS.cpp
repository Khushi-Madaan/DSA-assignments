/*Write a C++ program to implement Depth First Search (DFS) traversal 
of a graph.*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[100];
bool visited[100] = {false};
void DFS(int node)
{
    visited[node] = true;
    cout << node << " ";
    for (int x : adj[node])
    {
        if (!visited[x])
            DFS(x);
    }
}
int main()
{
    int v, e, a, b, start;
    cout << "Enter vertices and edges: ";
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << "Enter starting vertex: ";
    cin >> start;
    cout << "DFS: ";
    DFS(start);
    return 0;
}
