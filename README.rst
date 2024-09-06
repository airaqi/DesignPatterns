.. attention:: THIS IS A WORK IN PROGRESS PROJECT

===============
Design Patterns
===============

.. sectnum::

.. contents:: Table of Contents

Identification
==============

-------
Details
-------

.. csv-table::
    :width: 90%
    :widths: 20, 80
    :align: center
    :stub-columns: 1

    Project, Text Editor (Lexi)
    Book, Design Patterns Elements of Reusable Object-Oriented Software
    Author, airaqi
    Version, 1.0

---------------
Version Control
---------------

.. csv-table::
    :header-rows: 1
    :width: 90%
    :widths: 5, 20, 20, 55
    :align: center

    "Version","Date","Author","Description"
    "1.0","2024-08-04", "Ahmed Iraqi", "Draft Version"


Overview
========

While reading the book as everyone else I thought that its impossible to appreciate those patterns
unless they are implemented in code, in order to get the feeling of the goal of those paterns,
and the ultimate goal is to get the taste of mixing and matching patterns in one solution, and this
goal cannot be achieved except by implementing chapter two case study in full.

This project contains all patterns sample codes, and test cases verifiying that they works
properly, and also the case study implementation of the Lexi Text Editor.

.. note:: 

    Working on this project went through all software development cycle, all the way through
    requirements gathering (during reading the book), design, implementation, testing, and
    deployment, and some post deployment technical support usage.

Patterns
========

All patterns structures has been documented and samples has been implemented.

.. csv-table::
    :header-rows: 1
    :width: 90%
    :align: center

    "Category", "Pattern","Description"
    "Creational", `Abstract Factory <workspace/projects/patterns/abstract_factory/>`_, "Provide an interface for creating families of related or dependent objects without specifying their concrete classes."
    "", `Builder <workspace/projects/patterns/builder/>`_, "Separate the construction of a complex object from its representation so that the same construction process can create different representations."
    "", `Factory Method <workspace/projects/patterns/factory_method/>`_, "Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses."
    "", `Prototype <workspace/projects/patterns/prototype/>`_, "Specify the kinds of objects to create using a prototypical instance, and create new objects by copying this prototype."
    "", `Singleton <workspace/projects/patterns/singlton/>`_, "Ensure a class only has one instance, and provide a global point of access to it."
    "Structural", `Adapter <workspace/projects/patterns/adapter>`_, "Convert the interface of a class into another interface clients expect."
    "", `Bridge <workspace/projects/patterns/bridge/>`_, "Decouple an abstraction from its implementation so that the two can vary independently."
    "", `Composite <workspace/projects/patterns/composite/>`_, "Compose objects into tree structures to represent part-whole hierarchies."
    "", `Decorator <workspace/projects/patterns/decorator/>`_, "Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality"
    "Behavioural", `Command <workspace/projects/patterns/command/>`_, "Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations."
    "", `Iterator <workspace/projects/patterns/iterator/>`_, "Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation."
    "", `Memento <workspace/projects/patterns/memento>`_, "Without violating encapsulation, capture and externalize an object's internal state so that the object can be restored to this state later."
    "", `Strategy <workspace/projects/patterns/strategy/>`_, "Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it."
    "", `Visitor <workspace/projects/patterns/visitor/>`_, "Represent an operation to be performed on the elements of an object structure"

Lexi Test Editor
================

Lexi text editor case study provided in chapter two has been implemented in lexi project
refer to lexi project in `here <workspace/projects/lexi>`_

Strucure & Usage
================

Implementing the project has been organized into several libraries, as follows

.. csv-table::
    :header-rows: 1
    :width: 90%

    "module", "description"
    "common", "Common classes used in all projects, e.g. List, Iterator, Point ... etc."
    "lexi", "Lexi Text Editor implementation"
    "patterns", "Pattern samples implementations"


-----
Usage
-----

To build the project run the following commands on the terminal window, starting from the
project root:

.. code-block:: shell

    cd workspace/projects
    cmake -B ../build -DCMAKE_EXPORT_COMPILE_COMMANDS=1
    cmake --build ../build/

To run the tests:

.. code-block:: shell

    ctest -T memcheck --test-dir ../build/

To run pattern applications

.. code-block:: shell

    ../build/patterns/<pattern_name>/<pattern_name>_app
