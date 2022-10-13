#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

//  Data structure to store a graph edge
struct Edge {
	int source, dest, weight;
};

//  Data structure to store a heap node
struct Node {
	int vertex, weight;
};

//  A class to represent a graph object
class Graph
{
public:
	//  Vector of vectors of 'Edge' to represent an adjacency list
	vector<vector<Edge>> adjList;

	//  Graph constructor
	Graph(vector<Edge> const& edges, int n)
	{
		//  Resize the vector to hold 'n' elements of type vector<Edge>
		adjList.resize(n);

		//  Add edges to the directed graph
		for (Edge const& edge : edges)
		{
			//  Insert at the end
			adjList [edge.source].push_back(edge);
		}
	}
};

void printPath(vector<int> const& prev, int i, int source)
{
	if (i < 0)
	{
		return;
	}
	printPath(prev, prev[i], source);
	if (i != source)
	{
		cout << ", ";
	}
	cout << i;
}

int main()
{

}
