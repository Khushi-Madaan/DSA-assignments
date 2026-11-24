/*Write a C++ program to implement Breadth First Search (BFS) traversal 
of a graph.*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int v, e, a, b, start;
    cout << "Enter vertices and edges: ";
    cin >> v >> e;
    vector<int> adj[100];
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool visited[100] = {false};
    queue<int> q;
    cout << "Enter starting vertex: ";
    cin >> start;
    visited[start] = true;
    q.push(start);
    cout << "BFS: ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int x : adj[node])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return 0;
}
