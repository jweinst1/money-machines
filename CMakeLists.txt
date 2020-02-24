cmake_minimum_required(VERSION 3.1)

project(money_machines VERSION 0.0.1)

# Option to install targets to env location
if(DEFINED ENV{MONEY_MACHINES_HOME})
     message("-- Will install TEMPLATE binaries and libraries to location: " $ENV{MONEY_MACHINES_HOME})
	 set(CMAKE_INSTALL_PREFIX $ENV{MONEY_MACHINES_HOME})
else(DEFINED ENV{MONEY_MACHINES_HOME})
     message("-- Will install money machines binaries and libraries to location: " ${CMAKE_CURRENT_BINARY_DIR})
	 set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR})
endif(DEFINED ENV{MONEY_MACHINES_HOME})


# Disable some windows specific warnings for using more modern c functions
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# Options
option(WITH_testing "Allows tests to be run" ON)

if(WITH_testing MATCHES ON)
   enable_testing()
endif(WITH_testing MATCHES ON)
