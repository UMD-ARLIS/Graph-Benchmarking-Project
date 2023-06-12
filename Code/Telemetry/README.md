# Telemetry

All files relating to the measurement of performance of each Graph Problem against each Dataset

## Definitions of Metrics we will use, and methods to measure them. 
Populate once we decide what to do

**Performance** Measured in Giga Traversed Edges Per Second [Source: HIVE Workload Analysis Report pg 15](https://drive.google.com/file/d/1qM5POYo0vB9p-QKb88oNzzED2a7cJdW_/view?usp=drive_link)

**Efficency** Measured in Giga Traversed Edges Per Second Per Watt [Source: HIVE Workload Analysis Report pg 15](https://drive.google.com/file/d/1qM5POYo0vB9p-QKb88oNzzED2a7cJdW_/view?usp=drive_link)

## Survey of Metrics
Add in links / descriptions of metrics we can / should use. Sourcing essential. You can add a hyperlink in Markdown by using squarebrackets and parentheses: "\[\]\(\)" Where the text to display is in the brackets and the link is in the parentheses. 

## Survey of Tools, libraries and existing code. 
Add in links / descriptions of methods, tools, libraries etc we can / should use. Sourcing essential. You can add a hyperlink in Markdown by using squarebrackets and parentheses: "\[\]\(\)" Where the text to display is in the brackets and the link is in the parentheses. 

### GASCT
Intel's Gather, Apply, Scatter,  Compute-on-Target performance model extends the Bulk Synchronous Parallel (BSP) model of computation to support both pull and push based algorithms. It is what intel uses in their projections of PiUMA performance. [Source: HIVE Workload Analysis Report pg 18](https://drive.google.com/file/d/1qM5POYo0vB9p-QKb88oNzzED2a7cJdW_/view?usp=drive_link)

### Piuma Analytic Performance Model

T~estimate~ = $MAX(T~mem~,T~comp~,T~net~) + T~barrier~