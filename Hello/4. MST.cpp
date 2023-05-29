#include <iostream>  // Include the iostream library for input/output operations
#include <vector>  // Include the vector library for working with dynamic arrays
#include <queue>  // Include the queue library for working with queues
#include <climits>  // Include the climits library for working with integer limits

using namespace std;  // Use the standard namespace

// Structure to represent a graph edge
struct Edge {
    int source, destination, weight;  // Variables to store the source, destination, and weight of an edge
};

// Structure to represent a node in the graph
struct Node {
    int vertex, distance;  // Variables to store the vertex and its distance
};

// Comparator for the priority queue in the Greedy search algorithm
struct NodeComparator {
    bool operator()(const Node& lhs, const Node& rhs) const {
        return lhs.distance > rhs.distance;  // Compare the distances of two nodes in the priority queue
    }
};

// Function to find the MST using the Greedy search algorithm
void findMST(vector<vector<Edge>>& graph, int startVertex) {
    int numVertices = graph.size();  // Get the number of vertices in the graph
    vector<bool> visited(numVertices, false);  // Track visited vertices
    vector<int> parent(numVertices, -1);  // Track the parent of each vertex
    vector<int> distance(numVertices, INT_MAX);  // Track the minimum distance to each vertex

    // Create a priority queue for the Greedy search algorithm
    priority_queue<Node, vector<Node>, NodeComparator> pq;

    // Initialize the starting vertex
    distance[startVertex] = 0;
    pq.push({startVertex, 0});

    while (!pq.empty()) {
        // Get the vertex with the minimum distance from the priority queue
        int currentVertex = pq.top().vertex;
        pq.pop();

        visited[currentVertex] = true;

        // Explore all the adjacent vertices of the current vertex
        for (const auto& edge : graph[currentVertex]) {
            int neighbor = edge.destination;
            int weight = edge.weight;

            // If the neighbor vertex is not visited and the weight is smaller than the current distance,
            // update the distance and parent, and add it to the priority queue
            if (!visited[neighbor] && weight < distance[neighbor]) {
                distance[neighbor] = weight;
                parent[neighbor] = currentVertex;
                pq.push({neighbor, weight});
            }
        }
    }

    // Print the edges of the MST
    cout << "Minimum Spanning Tree Edges:" << endl;
    for (int i = 1; i < numVertices; i++) {
        cout << "(" << parent[i] << " - " << i << ")" << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    vector<vector<Edge>> graph(numVertices);  // Create a graph with the specified number of vertices

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;

        // Add the edge to the graph
        graph[source].push_back({source, destination, weight});
        graph[destination].push_back({destination, source, weight});
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    // Find the MST using the Greedy search algorithm
    findMST(graph, startVertex);

    return 0;
}

/* Enter the number of vertices in the graph: 5
Enter the number of edges in the graph: 7
Enter the edges (source, destination, weight):
0 1 2
0 2 3
1 2 1
1 3 4
2 3 2
2 4 3
3 4 1
Enter the starting vertex: 0*/
