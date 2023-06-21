// summer2023/Code/Utilities/dataLoader/dataLoader.c

//System Inclusions
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//Util Inclusions

# include "../c-utils/src/graph.h"
# include "../c-utils/src/fileutils.h"
# include "../c-utils/src/stringlib.h"

graph_t loadGraph(char *fileName, graph_t g, char mode){
	/*
	loadGraph takes in a file in our standard input and creates a graph base on the file
	INPUT ARGS: 
		fileName 	-	string	- The full path to the testFile
	PROCESS:
		Check if the filename is not null
		Break the file into lines
		Ignore the source and title lines
		When the Node mode is started, assume all following lines are nodes
		When the edge mode is started, assume all following lines are edges
	OUTPUT: 
		g 	- 	graph_t	- The graph created based on the input

	TODO / ISSUES: 
		ISSUE1: 	Currently only able to create edges based on the index of the node, rather than its metadata 'name'
		TODO1: 		Implement searching for node by Metadata for edge creation. 
		ISSUE2: 	Minimal input sanitization, very brittle to expected file format
		TODO2: 		Implement input sanitization 
		ISSUE3: 	Only able to create directed graphs
		TODO3: 		Add support for createing undirected graphs
	*/


	if (fileName == NULL || strcmp(fileName,"")==0 || strcmp(fileName," ")==0 || strcmp(fileName,"\n")==0){
		return(g);	
	}
	if (fs_identify_path(fileName) != FS_FILE){
		printf("\n\nERROR: FILE NOT FOUND: %s\n", fileName);
		return(g);
	}

	file_t f = f_init(fileName);							//Load the file

	f_parse_lines(f); 										//Break into lines
	char **lines = f_lines(f);

	bool nodeMode = false; 									//Used to track whether nodes or edges to be created
	bool edgeMode = false;
	int edgeCounter = 0;
	int adjacencyMatrix[(f_number_lines(f)/2)][(f_number_lines(f)/2)];

	for (int i=0; i<((f_number_lines(f)/2)+1);i++){ 		//Initialize the array. Logic is that the number of nodes is captured in the first half of the file. This is a little brittle though. 
		for (int j=0; j<((f_number_lines(f)/2)+1);j++){
		adjacencyMatrix[i][j] = 0;
		} 
	}

	
															//Iterate through each line in the file
    for (size_t i = 0; i < f_number_lines(f); i++){ 		
    														//Ignore Title and Source lines
    	if(s_find_str(lines[i],"#TITLE")!= -1 || s_find_str(lines[i],"#SOURCE")!= -1){
         	//printf("PASSING %s\n", lines[i]);
    	}
    														//Seeing "#NODES" activates Node mode
    	else if(s_find_str(lines[i],"#NODES")!= -1){
    		//printf("ACTIVATING NODE MODE\n");
    		edgeMode = false;
    		nodeMode = true;
    	}
    														//Seeing "#EDGES" activates edge mode
    	else if(s_find_str(lines[i],"#EDGES")!= -1){
    		//printf("ACTIVATING EDGE MODE\n");
    		nodeMode = false;
    		edgeMode = true;
    	}
    														//Depending on mode, create edges or nodes
    	else{
    		if (nodeMode == true && strcmp(lines[i],"") !=0 && strcmp(lines[i]," ") !=0 && strcmp(lines[i],"\n") !=0 && lines[i]!= NULL){
    			g_vertex_add(g, lines[i]);
				//int adjacencyMatrix[(g_num_vertices(g)+1)][g_num_vertices(g)+1];

    		}
    		if (edgeMode == true && strcmp(lines[i],"") !=0 && strcmp(lines[i]," ") !=0 && strcmp(lines[i],"\n") !=0 && lines[i]!= NULL){
    			int num = 0;
    			s_remove_unwanted_chars(lines[i], "()");
    			char **res = s_split_string_c(lines[i],',',&num);

				//printf("\nTrying to add edge (%s,%s)\n", res[0], res[1]);

				if (adjacencyMatrix[(atoi(res[0]))] [(atoi(res[1]))] != 1){

					g_edge_add(g, atoi(res[0]), atoi(res[1]), edgeCounter);		//res[0] is source, res[1] is dest
    				edgeCounter++;
					//printf("\nadded edge (%s,%s)\n", res[0], res[1]);
					adjacencyMatrix[(atoi(res[0]))] [(atoi(res[1]))] = 1;

					
					if (mode == 'u' && adjacencyMatrix[(atoi(res[1]))][(atoi(res[0]))] != 1) {
						g_edge_add(g, atoi(res[1]), atoi(res[0]), edgeCounter);		//res[0] is source, res[1] is dest
						edgeCounter++;
						//printf("\nadded reciprocal edge (%s,%s)\n", res[1], res[0]);
						adjacencyMatrix[(atoi(res[1]))] [(atoi(res[0]))] = 1;
					}
					else{
						//printf("Failed the inverse matrix check\n");
					}
				}
				else{
					//printf("Failed regular matrix check\n");
					//printf("The matrix value for [%s][%s] is %d", res[0], res[1], adjacencyMatrix[atoi(res[0])][atoi(res[1])]);
				}


    			
    		}

     }
    }

    //char *results = malloc(300*sizeof(char));  										//Hold the results

	//printf("NODES CREATED: %d, EDGES CREATED: %d", g_num_vertices(g), g_num_edges(g));

    //sprintf(results, "NODES CREATED: %d, EDGES CREATED: %d", g_num_vertices(g), g_num_edges(g));


    return(g);
	}
