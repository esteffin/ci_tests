# Copyright (C) 2020 IBM Corp.
# This program is Licensed under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance
# with the License. You may obtain a copy of the License at
#   http://www.apache.org/licenses/LICENSE-2.0
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License. See accompanying LICENSE file.

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
        $<INSTALL_INTERFACE:include/ci_test>
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
    ${CMAKE_CURRENT_BINARY_DIR}/ci_testConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY ExactVersion)

configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/ci_testConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ci_testConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_CMAKEDIR})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ci_testConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/ci_testConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_CMAKEDIR})

enable_testing()
add_subdirectory(tests)