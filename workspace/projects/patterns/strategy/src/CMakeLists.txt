add_library(strategy 
    composition.cpp 
    compositor.cpp 
    compositor_simple.cpp 
    compositor_tex.cpp 
    compositor_array.cpp)

target_link_libraries(strategy common)
