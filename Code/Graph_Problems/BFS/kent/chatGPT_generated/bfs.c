#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node** adjacencyList;
} Graph;

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    graph->adjacencyList = (Node**)malloc(numNodes * sizeof(Node*));

    int i;
    for (i = 0; i < numNodes; i++)
        graph->adjacencyList[i] = NULL;

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void breadthFirstSearch(Graph* graph, int startNode, int searchNode) {
    int* visited = (int*)calloc(graph->numNodes, sizeof(int));
    int* queue = (int*)malloc(graph->numNodes * sizeof(int));
    int front = 0, rear = 0;
    int currentNode, i;

    visited[startNode] = 1;
    queue[rear++] = startNode;

    printf("BFS traversal starting from node %d: ", startNode);

    while (front != rear) {
        currentNode = queue[front++];
        printf("%d ", currentNode);

        if (currentNode == searchNode) {
            printf("\nFound node %d\n", searchNode);
            free(visited);
            free(queue);
            return;
        }

        Node* temp = graph->adjacencyList[currentNode];
        while (temp != NULL) {
            int adjNode = temp->vertex;
            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                queue[rear++] = adjNode;
            }
            temp = temp->next;
        }
    }

    printf("\nNode %d not found\n", searchNode);
    free(visited);
    free(queue);
}

void freeGraph(Graph* graph) {
    if (graph == NULL)
        return;

    int i;
    for (i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjacencyList[i];
        while (temp != NULL) {
            Node* prev = temp;
            temp = temp->next;
            free(prev);
        }
    }

    free(graph->adjacencyList);
    free(graph);
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        printf("Usage: %s -i <input_file> -s <search_node>\n", argv[0]);
        return 1;
    }

    char* inputFile = argv[2];
    int searchNode = atoi(argv[4]);

    FILE* file = fopen(inputFile, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", inputFile);
        return 1;
    }

    int node1, node2;
    int maxNode = -1;

    while (fscanf(file, "%d %d", &node1, &node2) == 2) {
        if (node1 > maxNode)
            maxNode = node1;
        if (node2 > maxNode)
            maxNode = node2;
    }

    fclose(file);

    Graph* graph = createGraph(maxNode + 1);

    file = fopen(inputFile, "r");
    while (fscanf(file, "%d %d", &node1, &node2) == 2)
        addEdge(graph, node1, node2);

    fclose(file);

    breadthFirstSearch(graph, 0, searchNode);

    freeGraph(graph);

    return 0;
}
