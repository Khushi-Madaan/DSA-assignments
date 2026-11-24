/*Write a C++ program to implement Kruskal's algorithm to find the 
Minimum Spanning Tree (MST) of a weighted undirected graph.*/
#include <iostream>
#include <algorithm>
using namespace std;
struct Edge
{
    int u, v, w;
};
bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}
int parent[100];
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
int main()
{
    int v, e;
    Edge edges[100];
    cout << "Enter vertices and edges: ";
    cin >> v >> e;
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    for (int i = 0; i < v; i++)
        parent[i] = i;
    sort(edges, edges + e, compare);
    int cost = 0;
    cout << "MST edges:\n";
    for (int i = 0; i < e; i++)
    {
        int a = find(edges[i].u);
        int b = find(edges[i].v);
        if (a != b)
        {
            parent[a] = b;
            cost += edges[i].w;
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
        }
    }
    cout << "Minimum cost: " << cost;
    return 0;
}
