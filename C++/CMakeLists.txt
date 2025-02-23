cmake_minimum_required(VERSION 3.28)
project(DataStructures)

option(ENABLE_COVERAGE "Enable coverage reporting" ON)

if (ENABLE_COVERAGE)
    find_program(LCOV_PATH lcov)
    if(NOT LCOV_PATH)
        message(FATAL_ERROR "lcov not found! Please install lcov to generate coverage reports.")
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0 -g")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

include_directories(structures)

set(TEST_FILES
    tests/test_arr.cpp
    tests/test_hashtable.cpp
    tests/test_list.cpp
    tests/test_queue.cpp
    tests/test_stack.cpp
    tests/test_tree.cpp
)

set(SRC_FILES 
    src/arr.cpp
    src/hash.cpp
    src/list.cpp
    src/queue.cpp
    src/stack.cpp
    src/tree.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)

foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(EXE_NAME ${SRC_FILE} NAME_WE) 
    add_executable(${EXE_NAME} ${SRC_FILE})
endforeach()

add_executable(tests ${TEST_FILES})

find_package(GTest REQUIRED)
target_link_libraries(tests GTest::GTest GTest::Main)

if (ENABLE_COVERAGE)
    add_custom_target(clean_coverage
        COMMAND ${CMAKE_COMMAND} -E remove_directory coverage_html
        COMMAND ${CMAKE_COMMAND} -E remove -f *.gcda *.gcno coverage.info coverage_filtered.info
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

    add_custom_target(coverage
        COMMAND ${CMAKE_COMMAND} -E remove -f coverage.info coverage_filtered.info
        COMMAND lcov --ignore-errors unused --ignore-errors inconsistent --capture --directory . --output-file coverage.info --rc geninfo_unexecuted_blocks=1 --ignore-errors graph:mismatch:trace
        COMMAND lcov --ignore-errors unused --ignore-errors inconsistent --remove coverage.info "*/c++/*" "gtest*" "*/tests/*" "/usr/*" --output-file coverage_filtered.info
        COMMAND genhtml coverage_filtered.info --output-directory coverage_html
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating coverage report"
    )
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()
add_test(NAME RunTests COMMAND tests)