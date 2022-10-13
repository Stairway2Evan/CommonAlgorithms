/*  Time complexity of BFS traversal is O(V + E), where V and E are the total
	number of vertices and edges in the graph, respectively. Please note O(E)
	may vary between O(1) and O(V^2), depending on how dense the graph is.
*/
#include <iostream>
#include <queue>
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

	//  Graph constructor
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

//  Perform BFS recursively on the graph
void recursiveBFS(Graph const& graph, queue<int>& q, vector<bool>& discovered)
{
	if (q.empty())
	{
		return;
	}

	//  Dequeue front node and print it
	int v = q.front();
	q.pop();
	cout << v << " ";

	//  Do for every edge (v, u)
	for (int u : graph.adjList[v])
	{
		if (!discovered[u])
		{
			//  Mark it as discovered and enqueue it
			discovered[u] = true;
			q.push(u);
		}
	}

	recursiveBFS(graph, q, discovered);
}

int main()
{
	//  Vector of graph edges as per the above diagram
	vector<Edge> edges = {
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
	};

	//  Total number of nodes in the graph (labelled from 0 to 14)
	int n = 15;

	//  Build a graph from the given edges
	Graph graph(edges, n);

	//  To keep track of wheter a vertex is discovered or not
	vector<bool> discovered(n, false); // vector of size 'n', all initialized to 'false'
	
	//  Create a queue for doing BFS
	queue<int> q;

	//  Perform BFS traversal from all undiscovered nodes to cover all connected graph components
	for (int i = 0; i < n; i++)
	{
		if (discovered[i] == false)
		{
			//  Mark the source vertex as discovered
			discovered[i] = true;

			//  Enqueue source vertex
			q.push(i);

			//  Start BFS traversal from vertex 'i'
			recursiveBFS(graph, q, discovered);
		}
	}

	return 0;
}