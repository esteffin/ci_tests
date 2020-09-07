cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(ci_test 
        VERSION 0.0.1 
        LANGUAGES CXX)

include(GNUInstallDirs)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(HEADERS "src/prelude.h")
set(SRCS    "src/prelude.cpp")

add_library(ci_test SHARED ${HEADERS} ${SRCS})

target_include_directories(ci_test
    PUBLIC
        $<INSTALL_INTERFACE:ci_test>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_compile_options(ci_test 
                       PRIVATE -Wall -Wextra -Wpedantic)

set_target_properties(ci_test
                      PROPERTIES
                          OUTPUT_NAME "ci_test"
                          PUBLIC_HEADER "${HEADERS}")

install(TARGETS ci_test
    EXPORT ci_testTargets
    LIBRARY       DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ci_test
)

set(CMAKE_INSTALL_CMAKEDIR "${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME}")

install(EXPORT ci_testTargets DESTINATION ${CMAKE_INSTALL_CMAKEDIR})

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ci_testVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY ExactVersion)

configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/ci_test.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ci_test.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_CMAKEDIR})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ci_test.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/ci_testVersion.cmake
        DESTINATION ${CMAKE_INSTALL_CMAKEDIR})

enable_testing()
add_subdirectory(tests)