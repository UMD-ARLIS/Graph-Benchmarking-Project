// Code/Graph_Problems/CommunityDetection/Louvian/Sequential/louvian_sequential.h

// Structure to represent a node in the graph
typedef struct Node {
    int id;
    int community;
    int degree;
    struct Node** neighbors;
} Node;

// Structure to represent the graph
typedef struct Graph {
    int numNodes;
    Node** nodes;
} Graph;

Node* createNode(int id);

Graph* createGraph(int numNodes);

void addEdge(Graph* graph, int src, int dest);

double computeModularity(Graph* graph);

void louvain(Graph* graph);

void printCommunities(Graph* graph);



