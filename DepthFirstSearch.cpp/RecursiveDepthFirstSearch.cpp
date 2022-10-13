#include <iostream>
#include <vector>
using namespace std;

//  Data structure to store a graph edge
struct Edge
{
    int src, dest;
};

//  Class to represent a graph object
class Graph
{
public:
    //  Vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;

    //  Graph Constructor
    Graph(vector<Edge> const& edges, int n)
    {
        //  Resize the vector to hold 'n' elements of type 'vector<int>'
        adjList.resize(n);

        //  Add edges to the undirected graph
        for (auto& edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

//  Function to perform DFS traversal on the graph on a graph
void DFS(Graph const& graph, int v, vector<bool>& discovered)
{
    //  Mark the current node as discovered
    discovered[v] = true;

    //  Print the current node
    cout << v << " ";

    //  Do for every edge (v, u)
    for (int u : graph.adjList[v])
    {
        //  if 'u' is not yet discovered
        if (!discovered[u])
        {
            DFS(graph, u, discovered);
        }
    }
}

int main()
{
    //  Vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {1,2}, {1,7}, {1,8}, {2,3}, {2,6}, {3,4},
        {3,5}, {8,9}, {8,12}, {9,10}, {9,11}
    };

    //  Total number of nodes in the graph (labelled from 0 to 12)
    int n = 13;

    //  Build a graph from the given edges
    Graph graph(edges, n);

    //  To keep track of wheter a vertex is discovered or not
    vector<bool> discovered(n);

    //  Perform DFS traversal from all undiscovered nodes to
    //  cover all connected components of a graph
    for (int i = 0; i < n; i++)
    {
        if (discovered[i] == false)
        {
            DFS(graph, i, discovered);
        }
    }

    return 0;
}

/*  Time complexity of DFS traversal is O(V + E), where V and E are the 
    total number of vertices and edges, respectively. Note that O(E) may
    vary between O(1) and O(V^2), depending on how dense the graph is.*/
