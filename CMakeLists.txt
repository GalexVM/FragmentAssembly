cmake_minimum_required(VERSION 3.5.0)
project(FragmentAssembly VERSION 0.1.0 LANGUAGES C CXX)

add_executable(FragmentAssembly main.cpp node.h node.cpp graph.h graph.cpp)

add_custom_target(ejecutar_script_python
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/plotter.py
    DEPENDS FragmentAssembly
    COMMENT "Ejecutando script de Python para graficar el grafo"
    VERBATIM
)


