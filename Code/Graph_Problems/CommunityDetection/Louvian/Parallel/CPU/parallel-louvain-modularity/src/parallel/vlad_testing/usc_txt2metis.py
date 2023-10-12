#!/usr/bin/env python3

import sys
import getopt
import networkx as nx  # updated import statement


class Txt2MetisScript:
    def __init__(self, argv):
        self.argv = argv

    def usage(self):
        print("Usage: " + sys.argv[0] + " [-w] <in txt graph> <out metis graph>")
        print("Example: " + sys.argv[0] +
              " ../../../data/graphs/graph_ba_1k.txt ../../../data/graph_ba_1k.metis\n")
        print("\t[-h]              : This help message")
        print("\t[-w]              : Input graph has weights")
        print("\t<in txt graph>    : Input networkx txt graph")
        print("\t<out metis graph> : Output metis graph")
        sys.exit(1)

    def main(self):
        # Parse options
        try:
            opts, args = getopt.getopt(self.argv[1:], "wh", ["weight", "help"])
        except getopt.GetoptError as err:
            print(str(err))
            self.usage()
            return 1

        # Defaults
        useweight = False

        for o, a in opts:
            if o in ("-h", "--help"):
                self.usage()
                return 0
            elif o in ("-w", "--weight"):
                useweight = True
            else:
                print("Invalid option %s" % (o))
                return 1

        if len(args) != 2:
            self.usage()
            return 1

        infile = args[0]
        outfile = args[1]

        print("Converting graph %s from txt format to metis weighted edge format" % (infile))

        try:
            with open(infile, "r") as f:
                if useweight:
                    g = nx.read_weighted_edgelist(f, nodetype=int)
                else:
                    print("enters")
                    g = nx.read_edgelist(f, nodetype=int)
                    print("exits")
        except Exception as e:
            print("ERROR: Failed to read input graph due to: ", str(e))
            return 1

        # ... rest of the script remains unchanged
        if ((useweight) and ('weight' not in g.edges(data=True)[0][2])):
            print ("ERROR: Weight option specified yet no weights in graph")
            return(1)

        print ("Read %d nodes, %d edges" % (g.number_of_nodes(), g.number_of_edges()))

        # Sort the nodes in increasing order
        # snodes = g.nodes()
        snodes = list(g.nodes())
        snodes.sort(key=int)

        # Remove self loops
        selflist = []
        for s in snodes:
            if (s in g.neighbors(s)):
                selflist.append(s)

        print ("Removing %d self loops" % (len(selflist)))
        for s in selflist:
            g.remove_edge(s,s)

        # Save to file
        print ("Writing metis graph file %s" % (outfile))
        f = open(outfile, "w")
        if (useweight):
            f.write("%s %s 1\n" % (g.number_of_nodes(), g.number_of_edges()));
        else:
            f.write("%s %s\n" % (g.number_of_nodes(), g.number_of_edges()));

        # Iterate over each neighbor
        if (useweight):
            for s in snodes:
                for n in g.neighbors(s):
                    f.write("%d %d" % (int(n), g[s][n]['weight']))
                f.write("\n");
        else:
            for s in snodes:
                for n in g.neighbors(s):
                    f.write("%d " % (int(n)))
                f.write("\n");
        f.close()

        print ("Done")
        return 0

if __name__ == '__main__':
    prog = Txt2MetisScript(sys.argv)
    sys.exit(prog.main())
