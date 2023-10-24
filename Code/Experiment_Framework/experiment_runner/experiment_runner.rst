========================
Graph Benchmarking Project - Experiment Runner
========================

ABOUT
************************

The `Experiment Runner` is responsible for orchestrating and controlling the conduct of experiments. 

PROGRAM TESTING
************************
To test that the `Experiment Runner` is working, run the provided `test_experiment_runner.py` file
located in the `../tests` directory, using commands:

.. code-block:: python

    python ./tests/test_experiment_runner.py

PROGRAM EXECUTION
************************

Detail on how to invoke the experiment runner will be updated as completed. 

In general, it will: 

1) Accept as input a collection of .JSON documents that define the experiment(s) to be executed. 
2) Check that the required datasets exist. 
3) Check that the required reference implementations have been compiled and are working. 
4) Create each experiment.
5) Execute each experiment.
6) Generate reports on each experiment. 

OUTPUT
************************

The `Experiment Framework` will output a collection of reports to the `../../../Experiment_Results/Reports` directory

FURTHER INQUIRY
************************

LICENSING
************************
See `LICENSE.md https://github.com/UMD-ARLIS/Graph-Benchmarking-Project/LICENSE.md`_ for license information