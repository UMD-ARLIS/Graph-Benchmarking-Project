=======
C-Utils
=======

Taken directly from `barrust's c-util library
<https://github.com/barrust/c-utils/tree/master>`_ under an MIT License.

His project provides a collection of utility libraries to help reduce the need to write similar code for each project on an ad-hoc basis. It also has pretty good coverage of the code with unit tests.

Table of Contents
-----------------

- ``stringlib``: C-string utilities
- ``fileutils``: File system utilities
- ``bitarray``
- ``linked list``
- ``doubly linked list``
- ``stack``
- ``queue``
- ``graph``
- ``permutations``
- ``timing-c``: Code timing utility
- ``minunit``: Unit testing

Recommended External Libraries
------------------------------

- ``set``
- ``hashmap``
- ``bloom filter``
- ``kseq``: A fasta/fastq parser library
- ``utf-8``: Single header UTF-8 string functions for C and C++

Unit Tests
----------

Unit tests are provided using the minunit library. Each function is, hopefully, fully covered.

To run the unit-test suite, simply compile the test files using the provided Makefile with the command:

.. code-block:: shell

    make test

Note you'll need to create the ``/libs`` and ``/dist`` directories first in the c-utils root folder, using something like:

.. code-block:: shell

    mkdir libs
    mkdir dist

Then you can execute the tests using the executables:

.. code-block:: shell

    ./dist/bitarray
    ./dist/strlib
    ./dist/fileutils
    ./dist/graph
    ./dist/linkedlist
    ./dist/doublylinkedlist
    ./dist/stack
    ./dist/queue
    ./dist/permutations
    ./dist/minunit
    ./dist/timing
