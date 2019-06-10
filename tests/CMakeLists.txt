find_package (Threads)

add_executable(test_logger test_logger.cpp)
add_executable(test_state test_state.cpp)

set_target_properties(test_logger test_state gtest PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(test_logger
    gtest
    ${CMAKE_THREAD_LIBS_INIT}
    utils
    logger
)

target_link_libraries(test_state
    gtest
    ${CMAKE_THREAD_LIBS_INIT}
    utils
)

target_include_directories(gtest PRIVATE ${GTEST_INCLUDE_DIRS})

add_test(test_logger test_logger)
add_test(test_state test_state)

