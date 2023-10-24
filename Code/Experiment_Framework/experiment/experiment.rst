========================
Graph Benchmarking Project - Experiment
========================

ABOUT
************************

The `Experiment` class is a self-contained object that is able to execute an individual experiment.
The `Experiment Runner` class orchestrates collections of Experiment objects together to run an experiment suite. 
The `Experiment` class has subclasses (like `CPU_Experiment`, `GPU_Experiment`) that are specific to each hardware platform under test.  

PROGRAM TESTING
************************
To test that the `Experiment` is working, run the provided `test_experiment.py` file
located in the `../tests` directory, using commands:

.. code-block:: python

    python ../tests/test_experiment.py

PROGRAM INPUTS
************************

Placeholder - Generate from Code

PROGRAM EXECUTION
************************

In genearal, when initialized, an Experiment object will fill in the class parameters required to execute an experiment.

The parameters include user-provided values (e.g. name, dataset) and also internally generated information including a summary of the system the experiment is executing on and a summary of the dataset.

OUTPUT
************************

When initialized, the experiment parameter summary is dumped to:

``../../Experiment_Results/<experiment_name>/metadata.json``

When the experiment is complete, the raw experiment data (including time, memory, processing, power, etc. measurements) is dumped to:

``../../Experiment_Results/<experiment_name>/results.csv``

FURTHER INQUIRY
************************

LICENSING
************************
See `LICENSE.md https://github.com/UMD-ARLIS/Graph-Benchmarking-Project/LICENSE.md`_ for license information