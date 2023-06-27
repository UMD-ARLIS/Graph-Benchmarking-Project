// Code/Graph_Problems/CommunityDetection/Louvian/Parallel/louvian_parallel.h

// Structure definitions
typedef struct Node {
    int id;
    int community;
    int degree;
    struct Node** neighbors;
} Node;

typedef struct Graph {
    int numNodes;
    Node** nodes;
} Graph;

typedef struct ThreadArgs {
    Graph* graph;
    int start;
    int end;
} ThreadArgs;

// Global Variables
pthread_mutex_t mutex;  // Mutex for thread synchronization

// Function prototypes
Node* createNode(int id);
Graph* createGraph(int numNodes);
void addEdge(Graph* graph, int src, int dest);
double computeModularity(Graph* graph);
void processNode(Node* node, Graph* graph);
void* parallelLouvain(void* arg);
void printCommunities(Graph* graph);