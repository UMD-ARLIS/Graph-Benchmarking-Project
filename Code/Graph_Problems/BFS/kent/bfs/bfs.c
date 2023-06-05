// bfs.c


// Containing directory = "code/Graph_Problems/BFS/kent/bfs"
// up from bfs / kent / BFS / Graph_Problems / code
// then down into /Utilities/c-utils/src


// System Imports
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Util Imports

# include "../../../../Utilities/c-utils/src/graph.h"
# include "../../../../Utilities/c-utils/src/queue.h"
# include "../../../../Utilities/sets/src/set.h"

//Functions

char *breadthFirstSearch(graph_t g, int startNode, int searchTarget){

	/*
	breadthFirstSearch conducts a breadth first search of a graph
	INPUT ARGS:
		g 				- graph_t struct 	- the graph to be searched
		startNode 		- int 				- the node the search starts from (note: this is node index, not its name)
		searchTarget 	- int 				- the node being searched for (note: this is node index, not its name) 
	PROCESS:
		- Intialize a set and a queue
		- Add the start node to the queue
		- pop the queue, if its the target, success. 
		- If not target, traverse each edge, and if not visited before (not in set) add to queue
		- when the queue is empty, abort 
	OUTPUT
		traversalList 	- string 			- the list of visited nodes of the form "1,2,3"
	*/

	//Create data structures
	SimpleSet closed; 						//empty set
    set_init(&closed);
    queue_list_t fringe = q_init(); 		//Empty queue
    
    q_push(fringe, startNode); 				//Push start node to queue

    int graphSize = (g_num_vertices(g) +1); //used to determine how much memory needs to be allocated

    char *traversalList = malloc(2*graphSize*sizeof(char));	//Need to use malloc to assign to heap, rather than local stack. *2 to account for delimiting "," 

    while (q_num_elements(fringe) != 0){ 						//While fringe not empty
    	vertex_t current = g_vertex_get(g, q_pop(fringe)); 		//Pop the head
    	printf("%d\n", g_vertex_id(current)); 					//Get the associated vertex

    	if (g_vertex_id(current) == searchTarget){ 				//Case where current is the target
    		strcat(traversalList, g_vertex_metadata(current));
    		return traversalList;
    	}
    	else{ 													//Current is not target

    		if (set_contains(&closed, g_vertex_metadata(current)) == SET_FALSE) { 	//Current has not been visited before
    			set_add(&closed, g_vertex_metadata(current)); 						//Add current to the closed set 
    			
    			strcat(traversalList, g_vertex_metadata(current)); 					//Update traversal list
    			strcat(traversalList,","); 	
    			
    			unsigned int j; 													//accumulator variables for iterate edges
    			edge_t neighbour;
    			g_iterate_edges(current, neighbour, j) { 							//Step through each edge of the vertex and add to queue
        			vertex_t dest = g_vertex_get(g, g_edge_dest(neighbour));
        			q_push(fringe,g_vertex_id(dest));
    }
    		} 
    		else {
        		//Skip
    		}												
		
	    }
    }
    strcat(traversalList, "FAIL");								//Queue empty without finding target
    return traversalList;
}