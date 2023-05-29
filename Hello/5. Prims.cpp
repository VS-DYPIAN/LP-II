#include <iostream>
#include <climits>
using namespace std;

#define V 5 // Number of vertices in the graph

// Function to find the vertex with the minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX; // Initialize min value with maximum possible value
    int min_index;

    // Traverse all vertices
    for (int v = 0; v < V; v++)
    {
        // If the vertex is not yet included in MST and its key value is less than the current minimum
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v]; // Update the minimum value
            min_index = v; // Update the index of the minimum value
        }
    }

    return min_index; // Return the index of the vertex with the minimum key value
}


void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void primMST(int graph[V][V])
{
    int parent[V]; // Array to store constructed MST
    int key[V]; // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0; // First node is always the root of MST
    parent[0] = -1; // First node is the root, so it has no parent

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet); // Pick the minimum key vertex from the set of vertices not yet included in MST
        mstSet[u] = true; // Add the picked vertex to the MST Set

        // Update key value and parent index of the adjacent vertices of the picked vertex
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main()
{
    int graph[V][V];

    cout << "Enter the adjacency matrix of the graph (5x5):\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j]; // Read the input value and store it in the corresponding cell (i, j)
        }
    }

    primMST(graph); // Find and print the Minimum Spanning Tree for the given graph

    return 0;
}

/* Enter the adjacency matrix of the graph (5x5):
0  2  3  0  0  
2  0  1  4  0
3  1  0  3  2 
0  4  2  0  1 
0  0  3  1  0  */