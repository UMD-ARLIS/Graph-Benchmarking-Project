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


struct Graph* createGraph(struct Edge edges[], int numEdges);

void printGraph(struct Graph* graph);

void* bfsThread(void* arg);

const char* bfs(struct Graph* graph, int startVertex);
