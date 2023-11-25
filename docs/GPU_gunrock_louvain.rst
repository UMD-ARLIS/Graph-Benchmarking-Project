============================
Gunrock: GPU Graph Analytics
============================

.. image:: https://github.com/gunrock/docs/raw/master/docs/_media/logo.png
   :align: center

.. image:: https://img.shields.io/github/license/gunrock/gunrock.svg
   :target: https://github.com/gunrock/gunrock/blob/master/LICENSE.TXT
   :alt: Apache 2

.. image:: https://img.shields.io/github/issues/gunrock/gunrock.svg
   :target: https://github.com/gunrock/gunrock/issues
   :alt: Issues Open

.. image:: https://codecov.io/gh/gunrock/gunrock/branch/master/graph/badge.svg

.. image:: https://img.shields.io/badge/nvidia-accelerated%20library-green.svg?logo=nvidia
   :target: https://developer.nvidia.com/gpu-accelerated-libraries

.. image:: https://img.shields.io/badge/rapids-contributor-%237400ff.svg
   :target: https://rapids.ai/community.html



⚡**This version of Gunrock is deprecated, please use `main` or `develop` branch for new features. Some of the algorithms from `1.x.x` still need to be ported, for those, please use `master` or `dev` branch.**

**Gunrock** is a CUDA library for graph-processing designed specifically for the GPU. It uses a **high-level**, **bulk-synchronous**, **data-centric abstraction** focused on operations on vertex or edge frontiers. Gunrock achieves a balance between performance and expressiveness by coupling high-performance GPU computing primitives and optimization strategies, particularly in the area of fine-grained load balancing, with a high-level programming model that allows programmers to quickly develop new graph primitives that scale from one to many GPUs on a node with small code size and minimal GPU programming knowledge. For more details, see `Gunrock's Overview <https://gunrock.github.io/docs/#/gunrock/overview>`_.

.. toctree::
   :maxdepth: 2

   cmake
   dataset
   examples
   gunrock
   tools
   unittests


Quick Start Guide
-----------------

Before building Gunrock make sure you have **CUDA Toolkit 10.2 or higher** installed on your Linux system. We also support building Gunrock on docker images using the provided docker files under `docker` subdirectory. For complete build guide, see `Building Gunrock <https://gunrock.github.io/docs/#/gunrock/building_gunrock>`_.

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
- Comprehensive `list <https://gunrock.github.io/docs/#/gunrock/gunrock_applications>`_ of test applications and primitives for most the functionality of Gunrock.
- `API Reference documentation <https://gunrock.github.io/gunrock>`_ (generated using doxygen).
- Find our `publications <https://gunrock.github.io/docs/#/gunrock/publications_and_presentations>`_, `presentations <https://gunrock.github.io/docs/#/gunrock/publications_and_presentations?id=presentations>`_, and `performance analysis <https://gunrock.github.io/docs/#/analysis/results>`_.

Copyright and License
---------------------

Gunrock is copyright The Regents of the University of California, 2013&ndash;2019. The library, examples, and all source code are released under `Apache 2.0 <https://github.com/gunrock/gunrock/blob/master/LICENSE.TXT>`_.

