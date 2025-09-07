#include <bits/stdc++.h>

using namespace std;

void adjacencyMatrixImplementation()
{
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    int adjMatrix[n + 1][m + 1] = {0};

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter edge (u, v): ";
        cin >> u >> v;

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph only
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void adjacenecyListImplementation()
{
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<int> adjList[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter edge (u, v): ";
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph only
    }

    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int neighbor : adjList[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

void weightedAdjacencyMatrixImplementation()
{
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    int adjMatrix[n + 1][m + 1] = {0};

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Enter edge (u, v, w): ";
        cin >> u >> v >> w;

        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // For undirected graph only
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void weightedAdjacencyListImplementation()
{
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<int, int>> adjList[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Enter edge (u, v, w): ";
        cin >> u >> v >> w;

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // For undirected graph only
    }

    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (const auto &neighbor : adjList[i])
        {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
}

int main()
{
    // adjacencyMatrixImplementation();
    // adjacenecyListImplementation();

    // weightedAdjacencyMatrixImplementation();
    // weightedAdjacencyListImplementation();

    return 0;
}