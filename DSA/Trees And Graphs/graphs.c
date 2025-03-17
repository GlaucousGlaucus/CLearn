#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX // Define infinity for unreachable nodes

// A structure to represent an adjacency list node
typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

// A structure to represent an adjacency list
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// A structure to represent a graph
typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

// A utility function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// A utility function to create a graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Adds an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    // Add an edge from src to dest
    AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list representation of a graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* temp = graph->array[v].head;
        printf("\n Adjacency list of vertex %d", v);
        while (temp) {
            printf("-> %d(weight=%d) ", temp->dest, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Dijkstra's Algorithm for shortest path
void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i

    // minHeap will store {vertex, distance from source}
    int minHeap[V];
    int heapSize = V;

    // Boolean array to track processed vertices
    int visited[V];

    // Initialize distances and processed flags
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        minHeap[i] = i;
        visited[i] = 0;
    }
    dist[src] = 0;

    while (heapSize > 0) {
        // Extract min distance vertex
        int u = -1, minDist = INF;
        for (int i = 0; i < heapSize; i++) {
            if (!visited[minHeap[i]] && dist[minHeap[i]] < minDist) {
                u = minHeap[i];
                minDist = dist[minHeap[i]];
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        // Reduce heap size
        for (int i = 0; i < heapSize; i++) {
            if (minHeap[i] == u) {
                for (int j = i; j < heapSize - 1; j++) {
                    minHeap[j] = minHeap[j + 1];
                }
                heapSize--;
                break;
            }
        }

        // Update distances of adjacent vertices
        AdjListNode* temp = graph->array[u].head;
        while (temp != NULL) {
            int v = temp->dest;
            if (!visited[v] && dist[u] != INF && dist[u] + temp->weight < dist[v]) {
                dist[v] = dist[u] + temp->weight;
            }
            temp = temp->next;
        }
    }

    // Print distances
    printf("\nVertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Main function to test the above code
int main() {
    int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 3, 4, 3);

    printGraph(graph);

    dijkstra(graph, 0);

    return 0;
}
