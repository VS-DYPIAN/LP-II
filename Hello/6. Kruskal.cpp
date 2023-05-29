#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set for union-find operations
struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        // Initialize each vertex as a separate set
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // Find the parent of a set
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // Union of two sets
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

// Comparator function to sort edges based on their weights in ascending order
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Function to find the Minimum Spanning Tree using Kruskal's algorithm
void kruskalMST(vector<Edge>& edges, int numVertices) {
    // Sort the edges in ascending order of their weights
    sort(edges.begin(), edges.end(), compareEdges);
    
    // Create a disjoint set to keep track of disjoint sets of vertices
    DisjointSet ds(numVertices);
    
    vector<Edge> mst; // Stores the edges of the MST
    
    for (const Edge& edge : edges) {
        int srcRoot = ds.find(edge.src);
        int destRoot = ds.find(edge.dest);
        
        // If including this edge does not create a cycle, add it to the MST
        if (srcRoot != destRoot) {
            mst.push_back(edge);
            ds.unionSets(srcRoot, destRoot);
        }
    }
    
    // Print the edges and their weights in the MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const Edge& edge : mst) {
        cout << edge.src << " - " << edge.dest << "\tWeight: " << edge.weight << endl;
    }
}

int main() {
    int numVertices, numEdges;
    
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    
    vector<Edge> edges(numEdges);
    
    cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    
    kruskalMST(edges, numVertices);
    
    return 0;
}
