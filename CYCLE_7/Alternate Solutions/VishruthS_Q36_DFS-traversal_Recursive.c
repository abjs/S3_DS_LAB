//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 7 QUESTION 1
//Program to perfom Depth First Traversal on a graph 
//represented using the adjacency matrix

#include <stdio.h>
#include <stdbool.h>

#define V 11

int visited[V] = {0}; // to keep track of visited nodes

// ================ DEPTH FIRST TRAVERSAL ============== //
// Time complexity: O(V*V) (when using adjacency matrix of V vertices)
void depthFirstTraversal(int graph[][V], int u)
{
    visited[u] = 1;             // mark current node as visited
    printf("%d ", u);           // and print its value
    for (int i = 0; i < V; i++) // for every node in the graph
    {
        if (graph[u][i] == 1 && visited[i] == 0) // if it is adjacent and not visited
            depthFirstTraversal(graph, i);       // then go to that node
    }
}

void addEdge(int[][V], int, int);

// === MAIN FUNCTION === //
int main()
{
    int graph[V][V] = {0}; // initiliazing Adjacency Matrix

    addEdge(graph, 1, 2); // adding edges between graph nodes
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 7);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 10);
    addEdge(graph, 3, 9);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 5, 8);
    addEdge(graph, 7, 8);

    printf("\nDepth first traversal from node 1\n");
    depthFirstTraversal(graph, 1);

    return 0;
}

// Function to add an edge between two vertices of an Undirected graph
void addEdge(int graph[][V], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}