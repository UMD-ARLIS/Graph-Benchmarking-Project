# Telemetry

All files relating to the measurement of performance of each Graph Problem against each Dataset

## Definitions of Metrics we will use, and methods to measure them. 
Populate once we decide what to do

**Performance** Measured in Giga Traversed Edges Per Second [Source: HIVE Workload Analysis Report pg 15](https://drive.google.com/file/d/1qM5POYo0vB9p-QKb88oNzzED2a7cJdW_/view?usp=drive_link)

**Efficency** Measured in Giga Traversed Edges Per Second Per Watt [Source: HIVE Workload Analysis Report pg 15](https://drive.google.com/file/d/1qM5POYo0vB9p-QKb88oNzzED2a7cJdW_/view?usp=drive_link)

## Survey of Metrics
Add in links / descriptions of metrics we can / should use. Sourcing essential. You can add a hyperlink in Markdown by using squarebrackets and parentheses: "\[\]\(\)" Where the text to display is in the brackets and the link is in the parentheses. 

## Survey of Tools, libraries and existing code. 

### PERF
NOTE: Requires Linux to run:

[perf](https://perf.wiki.kernel.org/index.php/Main_Page) is powerful: it can instrument CPU performance counters, tracepoints, kprobes, and uprobes (dynamic tracing). It is capable of lightweight profiling. 

Performance counters are CPU hardware registers that count hardware events such as instructions executed, cache-misses suffered, or branches mispredicted. They form a basis for profiling applications to trace dynamic control flow and identify hotspots. *perf* provides rich generalized abstractions over hardware specific capabilities. Among others, it provides per task, per CPU and per-workload counters, sampling on top of these and source code event annotation.

Tracepoints are instrumentation points placed at logical locations in code, such as for system calls, TCP/IP events, file system operations, etc. These have negligible overhead when not in use, and can be enabled by the perf command to collect information including timestamps and stack traces. perf can also dynamically create tracepoints using the kprobes and uprobes frameworks, for kernel and userspace dynamic tracing

To use perf on your linux machine, assuming we are working with *myCode.c*:

1. Compile the code (note that the -g flag tells the compiler to compile with debugging information):

        gcc -g -c myCode.c -o myCode.o

2. Invoke perf to instrument the code:

        perf record ./myCode.o
    
3. Access the report in the directory that you ran perf record (accesses the outputted *perf.data* file):

        perf report

4. More can be viewed using the annotated viewer in the same directory with

        perf annotate
        
If in doubt, use the included manual to figure out what to do, from the command line run:

        man perf

### GNU GPROF
NOTE: Requires Linux to Run

[The GNU Profiler (GPROF)](http://web.archive.org/web/20141129061523/http://www.cs.utah.edu/dept/old/texinfo/as/gprof.html#SEC2) can be used to determine which parts of a program are taking most of the execution time.

To use it, all we do is add some additional flags to the compiler, whether we are using CC or GCC both should work. Assuming that we're working with a file called *myCode.c* we would use it as follows: 

1. Compile the code

        gcc -g -c myCode.c -o myCode_profile.o -pg
    
2. We then need to run the program that has been instrumented by GPROF: 


        ./myCode_profile.o

3. Running the code should output a file called *gmon.out* to the directory that you ran the above code in. To analyze the outputs we would use something like the following (noting that routing the output to a file called report.txt is optional: 

        gprof myCode_profile.o gmon.out > report.txt
    
**SO WHAT?** Pending further experimentation, this looks like it will be useful for understanding the efficency of the code that we run, and some of the temporal aspects, but will be less useful for the memory and power analysis aspects of the code. 
    
### VALGRIND
NOTE: Requires Linux to Run: 

[VALGRIND](https://valgrind.org/docs/manual/quick-start.html) is a suite of debugging and profiling tools. 

**MEMCHECK**

The most popular of the VALGRIND tools is called Memcheck. It can detect many memory-related errors that are common in C and C++ programs and that can lead to crashes and unpredictable behaviour.

To use it on your linux machine, assuming we are working with *myCode.c*:

1. Compile the code (note that the -g flag tells the compiler to compile with debugging information):

        gcc -g -c myCode.c -o myCode.o

2. Invoke Valgrind memCheck:

        valgrind --leak-check=yes ./myCode.o
    
3. Read through the results!

There's plenty more information in the [Valgrind Manual](https://valgrind.org/docs/manual/manual.html)

**CACHEGRIND**

[Cachegrind and cgannotate](https://valgrind.org/docs/manual/cg-manual.html) Cachegrind is a high-precision tracing profiler. It runs slowly, but collects precise and reproducible profiling data. It can merge and diff data from different runs.

To use Cachegrind, assuming we are interested in the file myCode.c:

1. Compile the code (note that the -g flag tells the compiler to compile with debugging information):

        gcc -g -c myCode.c -o myCode.o

2. Invoke Valgrind CacheGrind:

        valgrind --tool=cachegrind --cachegrind-out-file=myCode_cg.out ./myCode.o
    
3. Feed the results into cg_annotate and read the report:

        cg_annotate myCode_cg.out

### GASCT
Intel's Gather, Apply, Scatter,  Compute-on-Target performance model extends the Bulk Synchronous Parallel (BSP) model of computation to support both pull and push based algorithms. It is what intel uses in their projections of PiUMA performance. [Source: HIVE Workload Analysis Report pg 18](https://drive.google.com/file/d/1qM5POYo0vB9p-QKb88oNzzED2a7cJdW_/view?usp=drive_link)

### Piuma Analytic Performance Model
[Source: HIVE Workload Analysis Report pgs 20-22](https://drive.google.com/file/d/1qM5POYo0vB9p-QKb88oNzzED2a7cJdW_/view?usp=drive_link)
The PiUMA analytic performance model seeks to determine the limiting resource. It uses the $MAX$ operation because the implementation does not follow a bulk-synchronous model. PiUMA is a global memory access machine, and so accesses over the network are just accesses to memory, resulting in an overlap between then $T_{net}$ and $T_{comp}$ (and hence drives use of the MAX value). 

$$T_{estimate} = MAX(T_{mem},T_{comp},T_{net}) + T_{barrier}$$

**Memory Access Time Calculation**
$T_{mem}$ is the time taken to access memory assuming that memory is being driven at peak bandwidth. If it's not at peak, then it will not be the limiting component of the system. Note that while simple kernels (i.e. one task at a time) only need one calculation, complex tasks that occur in multiple phases, and are a sequence of multiple kernels. As a result, $T_{mem}$ will be the sum of each of the component phases.

$$T_{mem}={Bytes Accessed Mem \over mem_{bw}}$$

**Network Access Time Calculation**
$T_{net}$ is the amount of traffic crossing the bisection of the network.


$$T_{net}={BytesThroughBisection \over netBisection_{bw}}$$

**Compute Time**
$T_{comp}$ is modelled on the effective instructions per cycle (IPC) & is measured from real code executed in the PiUMA simulators. Effective IPC depends on how well the memory access latency is hidden from the core. For a memory access to stall the pipeline, its average latency needs to be greater than the number of threads in each of the MTPs. In PiuMA the number of threads is 16, so the average latency needs to be < 16 cycles. $n_iter$ here is the number of times a loop body is executed

$$T_{comp}={nIter * avgInstructionsPerIter \over IPC_{effective}}$$

**Barrier Time**
estimated using the span of the PIUMA system at each level of the hierarchy. It is assumed that the barrier will be performed through the memory, with each thread first completing a barrier within a core by performing atomic operations on the core-local scratchpad memory. Once the threads inside the cores complete the barrier, one thread from each core performs the same operation across all cores in a die and consecutively across the dies in a socket.



