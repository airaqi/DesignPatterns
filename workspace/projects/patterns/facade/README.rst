-----------------
Facade Pattern
-----------------

Provide a unified interface to a set of interfaces in a subsystem. Facade defines a
higher-level interface that makes the subsystem easier to use.

.. note:: Example Code
    The example code used here is a migration from Dragon Compilers book.

Usage
------
to compile an example application based on AST in the book is:


.. code-block:: console
    
    $ ./build/projects/facade/facade_app -f <input-file> -d <output-file> -l <log-level> -h

**-h**
    display usage help screen and exit.
**-f <input-file>**
    the path to the input file
**-d <output-file>**
    destination file to save
**-l <log-level>**
    set log level, default is info

    #. none
    #. fatal
    #. error
    #. warning
    #. info
    #. debug
    #. verbose

Structure
---------

.. figure:: docs/structure.svg
   :width: 842
   :height: 731
   :scale: 70%
   :figwidth: 90%
   :alt: Facade Pattern Structure
   :align: center

Example
-------

The example used is the same as the sample code below.

Sample Code
-----------

.. figure:: docs/sample_code.svg
   :width: 1227
   :height: 4365
   :scale: 80%
   :figwidth: 90%
   :alt: Facade Pattern Structure
   :align: center

