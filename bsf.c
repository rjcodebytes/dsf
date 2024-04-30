#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct AdjListNode *head;
};

// Structure to represent a graph. A graph is an array of adjacency lists.
struct Graph {
    int V;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to a directed graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to display the adjacency matrix
void displayAdjMatrix(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            int found = 0;
            struct AdjListNode* temp = graph->array[i].head;
            while (temp != NULL) {
                if (temp->dest == j) {
                    found = 1;
                    break;
                }
                temp = temp->next;
            }
            printf("%d ", found);
        }
        printf("\n");
    }
}

// Function to perform Breadth First Search
void BFS(struct Graph* graph, int start) {
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    int visited[MAX_VERTICES] = {0};

    // Mark the current node as visited and enqueue it
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal starting from vertex %d: ", start);
    while (front != rear) {
        // Dequeue a vertex from queue and print it
        int current = queue[front++];
        printf("%d ", current);

        // Get all adjacent vertices of the dequeued vertex current
        // If an adjacent has not been visited, then mark it visited and enqueue it
        struct AdjListNode* temp = graph->array[current].head;
        while (temp != NULL) {
            int adj = temp->dest;
            if (!visited[adj]) {
                visited[adj] = 1;
                queue[rear++] = adj;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Recursive function for Depth First Search
void DFSUtil(struct Graph* graph, int vertex, int visited[]) {
    // Mark the current vertex as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    struct AdjListNode* temp = graph->array[vertex].head;
    while (temp != NULL) {
        int adj = temp->dest;
        if (!visited[adj])
            DFSUtil(graph, adj, visited);
        temp = temp->next;
    }
}

// Function to perform Depth First Search
void DFS(struct Graph* graph, int start) {
    int visited[MAX_VERTICES] = {0};
    printf("DFS Traversal starting from vertex %d: ", start);
    DFSUtil(graph, start, visited);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int V = 5; // Number of vertices in the graph
    struct Graph* graph = createGraph(V);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 2);

    // Display adjacency matrix
    displayAdjMatrix(graph);
    printf("\n");

    // Prompt user to input the starting vertex for BFS and DFS traversal
    int start_vertex;
    printf("Enter the starting vertex for BFS and DFS traversal: ");
    scanf("%d", &start_vertex);

    // Perform BFS and DFS traversal
    BFS(graph, start_vertex);
    DFS(graph, start_vertex);

    return 0;
}

