import subprocess

def run_commands(commands):
    output = ""
    for command in commands:
        try:
            result = subprocess.check_output(command, shell=True, stderr=subprocess.STDOUT, text=True)
            output += f"Command: {command}\nOutput:\n{result}\n"
        except subprocess.CalledProcessError as e:
            output += f"Command: {command}\nError:\n{e.output}\n"

    return output

if __name__ == "__main__":
    commands = [
        #Run Each Command in Turn and collect the results:
        "./../GraphProblems/GraphMatching/vf3lib/bin/vf3 -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf",
        "./../GraphProblems/GraphMatching/vf3lib/bin/vf3 -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf",
        "./../GraphProblems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf a 1 -t 2",
        "./../GraphProblems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf a 1 -t 2",
        "./../GraphProblems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_3_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf a 1 -t 10",
        "./../GraphProblems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/SMALL_A.01/SMALL_SUB_4_pattern.grf ./../../Data/subgraph_matching/SMALL_A.01/SMALL_target.grf a 1 -t 10",
        # Add more commands if needed
    ]

    # Run commands and collect results
    result = run_commands(commands)

    # Output results to a file
    output_file_path = "results.txt"
    with open(output_file_path, "w") as file:
        file.write(result)

    print(f"Results have been saved to {output_file_path}.")
