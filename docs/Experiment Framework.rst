====================
Experiment Framework
====================

The experiment framework will become our way of building, monitoring, and executing experiments.

.. toctree::
   :maxdepth: 2

   Experiment
   Experiment_runner
   Tests
   run_sgm_cpu_medium.py
   run_sgm_cpu_small.py
   run_sgm_gpu_small.py


Getting started
---------------

Activate the environment, which should be done with something like:

.. code-block:: bash

   source ../../graph_benchmark_env/bin/activate

Create it at this location if you have to.

If not part of the environment already, install NetworkX:

.. code-block:: bash

   pip install networkx

Change into the test directory:

.. code-block:: bash

   cd tests

Run the current tests:

.. code-block:: bash

   python test_experiment.py

Current Functionality
---------------------

The experiment class tracks the common metadata across all types of experiments. It is capable of:

1. Tracking all relevant metadata.
2. Loading a graph from a file and generating summary metadata.
3. Logging timing information.
4. Profiling the operating system for Memory, CPU, Operating system, etc.
5. Dynamically creating required output directories for experiments and dumping experiment metadata to .json.

Future Work
-----------

1. Add Subclasses for CPU_Experiment and GPU_Experiment.
2. Add an "experiment runner" class that, given a .JSON of all required experiments, executes them according to provided parameters.

Testing Policy
--------------

No new features without a failing test.

No merging to main without all tests passing.
