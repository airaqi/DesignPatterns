-----------------
Observer Pattern
-----------------

Define a one-to-many dependency between objects so that when one object
changes state, all its dependents are notified and updated automatically.


Structure
---------

Patterns is composed of two interfaces **Subject** and **Observer**, which are implemented by **ConcreteSubject** and **ConcreteObserver** classes, which might be any typical classes in the application that needs to be notified by other objects status updates.

.. figure:: docs/structure.svg
   :width: 792
   :height: 332
   :scale: 90%
   :figwidth: 90%
   :alt: Observer Pattern Structure
   :align: center

Typical interactions between subjects and observers as as follows:


.. figure:: docs/standard_interaction.svg
   :width: 493
   :height: 342
   :scale: 90%
   :figwidth: 90%
   :alt: Observer Pattern Structure
   :align: center

Example
-------

.. figure:: docs/example.svg
   :width: 868
   :height: 501
   :scale: 90%
   :figwidth: 90%
   :alt: Facade Pattern Structure
   :align: center


Sample Code
-----------

.. figure:: docs/sample_code.svg
   :width: 925
   :height: 1025
   :scale: 70%
   :figwidth: 90%
   :alt: Facade Pattern Structure
   :align: center
