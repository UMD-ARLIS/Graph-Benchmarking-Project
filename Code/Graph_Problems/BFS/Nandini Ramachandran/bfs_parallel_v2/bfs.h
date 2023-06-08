// bfs.h

// Define the maximum number of vertices in the graph
#define NUM_VERTICES 6

struct Graph{
    struct Node* head[NUM_VERTICES];
};

struct Node{
    int end;
    struct Node* next;
};

struct Edge{
    int start;
    int end;
};

// Structure to hold BFS data
struct BFSData {
    struct Graph* graph;
    bool* visited;
    int* queue;
    int front;
    int rear;
    struct str_builder* path;
};


// Function to create a graph
struct Graph* createGraph(struct Edge edges[], int numEdges){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    // Sets all the head references to null
    for (int i = 0; i < NUM_VERTICES; i++){
        graph->head[i] = NULL;
    }
    
    // Build adjacency list representation of the graph
    for (int i = 0; i < numEdges; i++){
        // Get start and end vertices
        int start = edges[i].start;
        int end = edges[i].end;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->end = end;

        // Points the new node to the current head
        newNode->next = graph->head[start];
        // Points head to the new node
        graph->head[start] = newNode;
    }
    
    return graph;
}

void printGraph(struct Graph* graph);

void* bfsThread(void* arg);

const char* bfs(struct Graph* graph, int startVertex);
