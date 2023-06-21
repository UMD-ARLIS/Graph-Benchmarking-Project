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

struct Graph* createGraph(struct Edge edges[], int numEdges);

void printGraph(struct Graph* graph);

const char* bfs(struct Graph* graph, int startVertex);