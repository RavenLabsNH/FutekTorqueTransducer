cmake_minimum_required(VERSION 3.4)
project(pybind_test)

find_library(futekLib FUTEK_USB-x86_64)

if (${futekLib} STREQUAL futekLib-NOTFOUND)
    message(FATAL_ERROR "No FutekLib, sad day")
else()
    message(STATUS "futeklib Found! as ${futekLib}")
endif()

find_library(ftd2xxLib ftd2xx)

if (${ftd2xxLib} STREQUAL ftd2xxLib-NOTFOUND)
    message(FATAL_ERROR "No ftd2xxLib, sad day")
else()
    message(STATUS "ftd2xxLib Found! as ${ftd2xxLib}")
endif()



add_subdirectory(pybind11)
include_directories(thirdparty)
pybind11_add_module(bind_test main.cpp)
target_link_libraries(bind_test PUBLIC ${futekLib} ${ftd2xxLib})

