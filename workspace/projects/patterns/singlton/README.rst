<<< `Back </>`_


---------
Singleton
---------

Structure
---------

.. figure:: docs/singleton-structure.svg
   :width: 981
   :height: 539
   :scale: 60%
   :figwidth: 90%
   :align: center

   Figure 1.1: Standalone Singleton pattern (top) and an Inherited singleton (bottom)

Sample Code
-----------

Singleton pattern ensures that a class has one instance available in the application. This idiom has three several implementation variations, according to the project requirements.

First, that I call it the simple or streatforward singleton, in which each singleton class holds its own unique instance, which insures that we can only get one unique instance per class, but also we can have several factory instances of several types simultanously (refer to Figure: 1.2).

.. figure:: docs/singleton-simple-sample.svg
   :width: 943
   :height: 507
   :scale: 65%
   :figwidth: 90%
   :align: center

   Figure 1.2: Simple Inherited Singleton

Second, is the Fixed-Inheritance-Singleton, in which a base singleton class holds the singleton
inatance, which ensures that only one singleton can be instantiated at once, and clients can
request new instance by name, and only one factory is instanciated and saved for further
processing. (refer to Figure: 1.3)

.. figure:: docs/singleton-fixed-sample.svg
   :width: 730
   :height: 684
   :scale: 85%
   :figwidth: 90%
   :align: center

   Figure 1.3: Fixed Inherited Singleton

Last, is the Full-Inheritance-Singleton, in which base singleton manages a list of registered
singletons, and every singleton should register itself in that registry in order for instance
to avaiable for clients to recall, using the instance() method. (refer to Figure: 1.4)

.. figure:: docs/singleton-inherited-sample.svg
   :width: 1092
   :height: 847
   :scale: 57%
   :figwidth: 90%
   :align: center

   Figure 1.4: Full Inherited Singleton


.. note:: Singleton implementation can be found in the abstract factory sample code
