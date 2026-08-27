add_library(${LIBRARY_NAME}
    dummy.cpp
    subject.cpp
    observer.cpp
    console_window.cpp
    console_widget.cpp
    clock_timer.cpp
    clock_analog.cpp
    clock_digital.cpp
    
)

find_package(${X11_PKG} REQUIRED)

target_link_libraries(${LIBRARY_NAME} ${COMMON_LIB} ${X11_LIBRARIES} ${EXTRA_LINK_LIBS})
