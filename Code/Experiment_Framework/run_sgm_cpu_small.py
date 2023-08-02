import subprocess

def run_commands(commands):
    output = ""
    for command in commands:
        print("Running", command)
        try:
            result = subprocess.check_output(command, shell=True, stderr=subprocess.STDOUT, text=True)
            output += f"Command: {command}\nOutput:\n{result}\n"
            print("Completed Successfully")
        except subprocess.CalledProcessError as e:
            output += f"Command: {command}\nError:\n{e.output}\n"
            print("Failed")

    return output

if __name__ == "__main__":
    commands = [
        #Run the timing commands:
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3  -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf",
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3 -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf",
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf a 1 -t 2",
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf a 1 -t 2",
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf a 1 -t 10",
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf a 1 -t 10",
        #Run the Memory Commands
        "sudo valgrind --log-file=valgrind.out ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\\n\2 frees\\n\3 bytes allocated/'",        
        "sudo valgrind --log-file=valgrind.out ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\\n\2 frees\\n\3 bytes allocated/'",
        "sudo valgrind --log-file=valgrind.out ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf -a 1 -t 2; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\\n\2 frees\\n\3 bytes allocated/'",
        "sudo valgrind --log-file=valgrind.out ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf -a 1 -t 2; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\\n\2 frees\\n\3 bytes allocated/'",
        "sudo valgrind --log-file=valgrind.out ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf -a 1 -t 10; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\\n\2 frees\\n\3 bytes allocated/'",
        "sudo valgrind --log-file=valgrind.out ./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p  ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf -a 1 -t 10; grep total valgrind.out | sed -E 's/.*: ([0-9,]+) allocs, ([0-9,]+) frees, ([0-9,]+) bytes allocated/\1 allocs\\n\2 frees\\n\3 bytes allocated/'"



    
    ]

    # Run commands and collect results
    result = run_commands(commands)

    # Output results to a file
    output_file_path = "small_results.txt"
    with open(output_file_path, "w") as file:
        file.write(result)

    print(f"Results have been saved to {output_file_path}.")
