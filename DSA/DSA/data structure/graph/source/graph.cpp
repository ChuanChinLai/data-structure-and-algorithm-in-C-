#include <data structure\graph\graph.h>
#include <algorithm>
#include <queue>
#include <stack>

Graph::Graph(int i_numVertex): m_numVertex(i_numVertex)
{
	ASSERT(i_numVertex > 0);
	adj = new std::list<int>[m_numVertex];
}

Graph::~Graph()
{
	if (adj != nullptr)
	{
		delete[] adj;
		adj = nullptr;
	}
}

void Graph::addEdge(int Vertex_1, int Vertex_2)
{
	ASSERT(Vertex_1 < m_numVertex);
	ASSERT(Vertex_2 < m_numVertex);

	adj[Vertex_1].push_back(Vertex_2);
}

void Graph::destroy()
{
	Graph::~Graph();
}

void Graph::BFS(int i_Vertex)
{
	bool* visited = new bool[m_numVertex];

	for (size_t i = 0; i < m_numVertex; i++)
		visited[i] = false;

	std::queue<int> searchQueue;

	visited[i_Vertex] = true;
	searchQueue.push(i_Vertex);

	while (!searchQueue.empty())
	{
		int currentVertex = searchQueue.front();
		printf("%d  ", currentVertex);

		searchQueue.pop();

		for (std::list<int>::iterator i = adj[currentVertex].begin(); i != adj[currentVertex].end(); i++)
		{
			if (visited[*i] == false)
			{
				visited[*i] = true;
				searchQueue.push(*i);
			}
		}
	}
	delete[] visited;
}

void Graph::DFS(int i_Vertex)
{
	bool* visited = new bool[m_numVertex];

	for (size_t i = 0; i < m_numVertex; i++)
		visited[i] = false;

	std::stack<int> searchStack;

	visited[i_Vertex] = true;
	searchStack.push(i_Vertex);

	while (!searchStack.empty())
	{
		int currentVertex = searchStack.top();
		searchStack.pop();

		if(visited[currentVertex] == false)
			visited[currentVertex] = true;

		for (std::list<int>::iterator i = adj[currentVertex].begin(); i != adj[currentVertex].end(); i++)
		{
			if (visited[*i] == false)
			{
				searchStack.push(*i);
			}
		}

	}
	delete[] visited;
}
