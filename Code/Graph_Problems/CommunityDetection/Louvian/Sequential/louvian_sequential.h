// Code/Graph_Problems/CommunityDetection/Louvian/Sequential/louvian_sequential.h

// Structure Definitions
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

// Function Prototypes
Node* createNode(int id);
Graph* createGraph(int numNodes);
void addEdge(Graph* graph, int src, int dest);
double computeModularity(Graph* graph);
void louvain(Graph* graph);
void printCommunities(Graph* graph);



