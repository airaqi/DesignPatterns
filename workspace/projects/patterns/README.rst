---------
Patterns
---------

Add Pattern
-----------

Follow these steps to add new pattern:

1. Create pattern template

.. code-block:: shell

   $ cp .copyme <pattern_name>

2. rename pattern name in `./<pattern_folder>/CMakeLists.txt` with your pattern name.

.. code-block:: cmake

   ...
   set(PATTERN_NAME {<<=module_name=>>})
   ...

3. add new created folder to the `./CMakeLists.txt` 

.. code-block:: cmake

   ...
   add_subdirectory(<pattern_folder>)

4. add any dependencies required by the new pattern in `./<pattern_folder/CMakeLists.txt` and in `./<pattern_folder/test/CMakeLists.txt`
   you've got the pattern library, and X11, and doctest already included in all patterns.
