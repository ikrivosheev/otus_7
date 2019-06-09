configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h)

add_executable(bulk main.cpp)

add_library(utils version.cpp)

set_target_properties(bulk utils PROPERTIES
   CXX_STANDARD 14
   CXX_STANDARD_REQUIRED ON
   COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(bulk utils)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS bulk RUNTIME DESTINATION bin)
