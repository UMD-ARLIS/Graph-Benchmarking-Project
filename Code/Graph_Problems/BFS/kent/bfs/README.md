
## BFS Algorithm (from Kleinberg 1st ed)
Uses Multiple Lists

// u and v are nodes; 

// (u,v) is an edge between u and v;

// s is the source of the BFS

	BFS(s)
		Set Discovered[s] = true and Discovered[v] = false for all other v
		Initialize L[0] to consist of the single element s
		Set the layer counter i=0
		Set the current BFS tree T = Theta
		While L[i] is not empty: 
			Initialize an empty list L[i+1]
			For each node u that is an element of L[i]
				Consider each edge (u,v) incident to u
				If Discovered[v] = false then
					Set Discovered[v] = true
					Add edge (u,v) to the tree T
					Add v to the list L[i+1]
				EndIf
			EndFor
			Increment Layer Counter by 1
		EndWhile

## BFS Algorithm (From Berkley AI CS188 GraphSearch)

// problem is the graph

// fringe is a queue

// remove-front is a pop operation

// goal-test is checking if the search target is found

// state of a node doesn't really apply here, but in general is the name of the node. 

	function BFS (problem, fringe) return a solution, or failure
		closed <- an empty set
		fringe <- Insert(MAKE-NODE(INITIAL-STATE[problem]), fringe) 	
		loop do:
			if fringe is empty then 
				return failure
			node <- REMOVE-FRONT(fringe)
			if GOAL-TEST(problem, STATE[node]) 
				then return node
			if STATE[node] is not in closed then
				add STATE[node] to closed
				for child-node in EXPAND(STATE[node], problem) do
					fringe <- INSERT(child-node, fringe)
				end
		end