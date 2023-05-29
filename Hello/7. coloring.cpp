#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to check if it is safe to assign color c to vertex v
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& colors, int c)
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[v][i] && colors[i] == c)
            return false;
    }
    return true;
}

// Function to recursively solve graph coloring problem using backtracking
bool graphColoringUtil(vector<vector<int>>& graph, vector<int>& colors, int m, int v)
{
    if (v == graph.size())
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, colors, c))
        {
            colors[v] = c;
            if (graphColoringUtil(graph, colors, m, v + 1))
                return true;
            colors[v] = 0; // backtrack
        }
    }

    return false;
}

// Function to solve graph coloring problem using Branch and Bound with Backtracking
void graphColoring(vector<vector<int>>& graph, int m)
{
    vector<int> colors(graph.size(), 0); // Initialize colors of all vertices as 0

    if (graphColoringUtil(graph, colors, m, 0))
    {
        cout << "The graph can be colored using " << m << " colors:" << endl;
        for (int i = 0; i < graph.size(); i++)
            cout << "Vertex " << i << " --> Color " << colors[i] << endl;
    }
    else
    {
        cout << "No feasible solution exists for coloring the graph with " << m << " colors." << endl;
    }
}

int main()
{
    int numVertices, numEdges, numColors;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    // Create adjacency matrix to represent the graph
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    cout << "Enter the edges (u, v):" << endl;
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter the number of colors available: ";
    cin >> numColors;

    // Solve the graph coloring problem
    graphColoring(graph, numColors);

    return 0;
}

/* Enter the number of vertices in the graph: 5
Enter the number of edges in the graph: 6
Enter the edges (u, v):
0 1
0 2
1 2
1 3
2 3
3 4
Enter the number of colors available: 3 */
