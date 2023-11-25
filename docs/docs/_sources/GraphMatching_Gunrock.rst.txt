======================
Graph Matching Gunrock
======================

.. image:: https://github.com/gunrock/docs/raw/master/docs/_media/logo.png
   :target: https://github.com/gunrock/gunrock/

Gunrock GPU Graph Analytics
===========================

.. note::
   This version of Gunrock is deprecated. Please use the `main` or `develop` branch for new features. Some algorithms from `1.x.x` still need to be ported; for those, use the `master` or `dev` branch.

Gunrock is a CUDA library for graph processing designed for the GPU. It utilizes a high-level, bulk-synchronous, data-centric abstraction focusing on operations on vertex or edge frontiers. Gunrock achieves a balance between performance and expressiveness by coupling high-performance GPU computing primitives and optimization strategies. It also offers a high-level programming model that allows programmers to quickly develop new graph primitives that scale from one to many GPUs on a node with minimal GPU programming knowledge. For more details, see `Gunrock's Overview <https://gunrock.github.io/docs/#/gunrock/overview>`_.

Quick Start Guide
-----------------

Before building Gunrock, make sure you have **CUDA Toolkit 10.2 or higher** installed on your Linux system. You can also build Gunrock using Docker images provided in the `docker` subdirectory. For a complete build guide, see `Building Gunrock <https://gunrock.github.io/docs/#/gunrock/building_gunrock>`_.

.. code-block:: shell

   git clone --recursive https://github.com/gunrock/gunrock/
   cd gunrock
   mkdir build && cd build
   cmake .. && make -j$(nproc)
   make test

Getting Started with Gunrock
----------------------------

- To learn more about Gunrock and its programming model, see `Gunrock's Overview <https://gunrock.github.io/docs/#/gunrock/overview>`_.
- For information on building Gunrock, see `Building Gunrock <https://gunrock.github.io/docs/#/gunrock/building_gunrock>`_.
- Tutorial: `How to write a graph primitive within Gunrock? <https://gunrock.github.io/docs/#/devs/>`_
- Comprehensive list of `test applications and primitives <https://gunrock.github.io/docs/#/gunrock/gunrock_applications>`_ for most of the functionality of Gunrock.
- `API Reference documentation <https://gunrock.github.io/gunrock>`_ (generated using Doxygen).
- Find our `publications <https://gunrock.github.io/docs/#/gunrock/publications_and_presentations>`, `presentations <https://gunrock.github.io/docs/#/gunrock/publications_and_presentations?id=presentations>`, and `performance analysis <https://gunrock.github.io/docs/#/analysis/results>`_.

Copyright and License
---------------------

Gunrock is copyright The Regents of the University of California, 2013–2019. The library, examples, and all source code are released under the `Apache 2.0 License <https://github.com/gunrock/gunrock/blob/master/LICENSE.TXT>`_.
