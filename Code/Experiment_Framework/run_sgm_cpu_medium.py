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
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3  -v ./../../Data/subgraph_matching/MEDIUM_SUB_3_email-Enron.grf  ./../../Data/subgraph_matching/MEDIUM_email-Enron.grf",
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3 -v ./../../Data/subgraph_matching/MEDIUM_SUB_4_email-Enron.grf  ./../../Data/subgraph_matching/MEDIUM_email-Enron.grf",
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/MEDIUM_SUB_3_email-Enron.grf  ./../../Data/subgraph_matching/MEDIUM_email-Enron.grf a 1 -t 2",
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/MEDIUM_SUB_4_email-Enron.grf  ./../../Data/subgraph_matching/MEDIUM_email-Enron.grf a 1 -t 2",
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/MEDIUM_SUB_3_email-Enron.grf  ./../../Data/subgraph_matching/MEDIUM_email-Enron.grf a 1 -t 10",
        "./../Graph_Problems/GraphMatching/vf3lib/bin/vf3p -v ./../../Data/subgraph_matching/MEDIUM_SUB_4_email-Enron.grf  ./../../Data/subgraph_matching/MEDIUM_email-Enron.grf a 1 -t 10",
        # Add more commands if needed
    ]

    # Run commands and collect results
    result = run_commands(commands)

    # Output results to a file
    output_file_path = "medium_results.txt"
    with open(output_file_path, "w") as file:
        file.write(result)

    print(f"Results have been saved to {output_file_path}.")
