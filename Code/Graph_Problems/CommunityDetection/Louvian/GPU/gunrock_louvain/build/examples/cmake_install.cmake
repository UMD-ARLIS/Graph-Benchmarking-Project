# Install script for directory: /home/nanir/gunrock/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/nanir/gunrock/build/examples/bc/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/bfs/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/color/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/geo/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/hits/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/kcore/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/knn/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/louvain/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/pr/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/pr_nibble/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/proj/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/rw/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/sage/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/sm/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/snn/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/ss/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/sssp/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/tc/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/vn/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/lp/cmake_install.cmake")
  include("/home/nanir/gunrock/build/examples/lcc/cmake_install.cmake")

endif()

