/*Write a C++ program to implement Dijkstra's Shortest Path Algorithm
to find the shortest distance from a source vertex to all other 
vertices in a weighted graph.*/
#include <iostream>
using namespace std;
int main()
{
    int v, cost[100][100], dist[100], visited[100] = {0}, source;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            cin >> cost[i][j];
    cout << "Enter source vertex: ";
    cin >> source;
    for (int i = 0; i < v; i++)
        dist[i] = 9999;
    dist[source] = 0;
    for (int i = 0; i < v; i++)
    {
        int min = 9999, u = -1;
        for (int j = 0; j < v; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        if (u == -1)
            break;
        visited[u] = 1;
        for (int j = 0; j < v; j++)
        {
            if (cost[u][j] > 0 && !visited[j] && dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
        }
    }
    cout << "Shortest distances:\n";
    for (int i = 0; i < v; i++)
        cout << source << " to " << i << " = " << dist[i] << endl;
    return 0;
}
