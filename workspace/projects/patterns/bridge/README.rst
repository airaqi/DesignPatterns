.. raw:: html

    <style> td { border: 0px solid black; } </style>

--------------
Bridge Pattern
--------------

Structure
----------

.. figure:: docs/bridge_structure.svg
   :width: 775
   :height: 306
   :figwidth: 90%
   :scale: 80%
   :align: center

   Figure 1: Formal Bridge Pattern

Examples
--------

.. list-table:: Figure 2: Extending through inheritance causes class depth rush
    :width: 90%
    :align: center
    :widths: 45 5 45

    * - .. image:: docs/bridge_subclass_problem_1.svg
            :width: 226
            :height: 145
            :scale: 100%
            :align: right
      - =>
      - .. image:: docs/bridge_subclass_problem_2.svg
            :scale: 70%
            :width: 450
            :height: 241
            :align: left

.. figure:: docs/bridge_subclass_soluion.svg
   :width: 925
   :height: 398
   :figwidth: 90%
   :scale: 65%
   :align: center

   Figure 3: Bridge Design helps isolating abstractions from implementations

Sample Code
-----------
