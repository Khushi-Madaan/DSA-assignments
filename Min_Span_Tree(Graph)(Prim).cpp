/*Write a C++ program to implement Prim's algorithm to find the 
Minimum Spanning Tree (MST) of a weighted undirected graph.*/
#include <iostream>
using namespace std;
int main()
{
    int v, cost[100][100], visited[100] = {0};
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            cin >> cost[i][j];
    visited[0] = 1;
    int edges = 0, total = 0;
    cout << "MST edges:\n";
    while (edges < v - 1)
    {
        int min = 9999, a = -1, b = -1;
        for (int i = 0; i < v; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < v; j++)
                {
                    if (!visited[j] && cost[i][j] > 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a == -1)
        {
            cout << "Graph is not connected";
            return 0;
        }
        cout << a << " - " << b << " : " << min << endl;
        visited[b] = 1;
        total += min;
        edges++;
    }
    cout << "Minimum cost: " << total;
    return 0;
}
