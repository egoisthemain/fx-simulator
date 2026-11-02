cmake_minimum_required(VERSION 3.16)
project(fx_simulator LANGUAGES CXX)

add_executable(fx_simulator 
    src/main.cpp
    src/simulation.cpp
)
target_compile_features(fx_simulator PRIVATE cxx_std_17)

include (FetchContent)

FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    GIT_TAG v2.4.11
)

FetchContent_MakeAvailable(doctest)

enable_testing()

add_executable(simulation_tests
    tests/test_simulation.cpp
    src/simulation.cpp
)

target_compile_features(simulation_tests PRIVATE cxx_std_17)
target_include_directories(simulation_tests PRIVATE src)
target_link_libraries(simulation_tests PRIVATE doctest::doctest)

add_test(NAME simulation_tests COMMAND simulation_tests)

add_executable(simulation_benchmark
    benchmarks/benchmark_simulation.cpp
    src/simulation.cpp
)

target_compile_features(simulation_benchmark PRIVATE cxx_std_17)
target_include_directories(simulation_benchmark PRIVATE src)