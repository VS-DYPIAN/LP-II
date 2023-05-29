#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 100;

void bfs(int graph[][MAX], bool visited[], int node, int n, string nodevalues[])
{
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        if (!visited[current])
        {
            visited[current] = true;
            cout << nodevalues[current] << " ";

            for (int i = 0; i < n; i++)
            {
                if (graph[current][i] && !visited[i])
                {
                    q.push(i);
                }
            }
        }
    }
}

void dfs(int graph[][MAX], bool visited[], int node, int n, string values[])
{
    stack<int> s;
    s.push(node);

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (!visited[current])
        {
            visited[current] = true;
            cout << values[current] << " ";

            for (int i = n; i >= 0; i--)
            {
                if (graph[current][i] && !visited[i])
                {
                    s.push(i);
                }
            }
        }
    }
}

int main()
{
    int graph[MAX][MAX] = {0};
    bool visited[MAX] = {false};
    string nodevalues[MAX];

    int n, e;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter node values:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nodevalues[i];
    }

    cout << "Enter edge (node1, node2): ";
    int node1, node2;
    for (int i = 0; i < e; i++)
    {
        cin >> node1 >> node2;
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;
    }

    int choice;
    while (true)
    {
        cout << endl;
        cout << "1. BFS" << endl;
        cout << "2. DFS" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "BFS traversal: ";
           
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    bfs(graph, visited, i, n, nodevalues);
                }
            }
            cout << endl;
            break;

        case 2:
            cout << "DFS traversal: ";
            for (int i = 0; i < n; i++)
            {
                visited[i] = false;
            }
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    dfs(graph, visited, i, n, nodevalues);
                }
            }
            cout << endl;
            break;

        case 3:
            cout << "Exiting the program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
