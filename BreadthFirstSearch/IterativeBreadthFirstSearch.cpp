#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Data structure to storea graph edge
struct Edge
{
	int src, dest;
};

// Class to represent a graph object
class Graph
{
public:
	// A vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// Graph Constructor
	Graph(vector<Edge> const& edges, int n)
	{
		// resize the vector to hold 'n' elements of type 'vector<int>'
		adjList.resize(n); // remember 'resize' vector method

		// add eges to the undirected graph
		for (auto& edge : edges)
		{
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};

// Perform BFS on the graph starting from vertex 'v'
void BFS(Graph const& graph, int v, vector<bool>& discovered)
{
	// create a queue for doing BFS
	queue<int> q;

	// mark the source vertex as discovered
	discovered[v] = true;

	// enqueue source vertex
	q.push(v);

	// loop untill queue is empty
	while (!q.empty())
	{
		// dequeue front node and print it
		v = q.front();
		q.pop();
		cout << v << " ";

		// do for every edge (v, u)
		for (int u : graph.adjList[v])
		{
			if (!discovered[u])
			{
				// mark it as discovered and enqueue it
				discovered[u] = true;
				q.push(u);
			}
		}
	}
}

int main()
{
	// Vector of graph edgees as per the above diagram
	vector<Edge> edges = {
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
		// vertex 0, 12, and 14 are single nodes
	};

	// total number of nodes in the graph (labelled from 0 to 14)
	int n = 15;

	// build a graph from the given edges
	Graph graph(edges, n);

	// to keep track of whether a vertex is discovered or not
	vector<bool> discovered(n, false);

	/*  Perform BFS traversal from all undiscovered nodes to 
		cover all connected components of a graph
	*/
	for (int i = 0; i < n; i++)
	{
		if (discovered[i] == false)
		{
			//  start BFS traversal from vertex 'i'
			BFS(graph, i, discovered);
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu