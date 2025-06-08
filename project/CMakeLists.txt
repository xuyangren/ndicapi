cmake_minimum_required(VERSION 2.8)


if(POLICY CMP0020)
  cmake_policy(SET CMP0020 NEW)
endif()

project(MYSLAM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set( CMAKE_BUILD_TYPE "Release" )

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_COMPILER "gcc")

#NDI
set(NDI_FILE /home/xuyang/ndi/ndicapi/NDI-master)
INCLUDE_DIRECTORIES(${NDI_FILE}/library/include )
set(NDI_LIB ${NDI_FILE}/build/linux/libndicapi.so)
# ndicapi
find_package(ndicapi REQUIRED)
INCLUDE_DIRECTORIES(${ndicapi_INCLUDE_DIRS})

# Eigen3
find_package( Eigen3 REQUIRED )

#Sophus
find_package( Sophus REQUIRED)


INCLUDE_DIRECTORIES(
                ${PROJECT_SOURCE_DIR}
                ${EIGEN3_INCLUDE_DIR}
                ${Sophus_INCLUDE_DIRS}
                )

add_executable(${PROJECT_NAME}
main.cpp
nditrack.cpp
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
         ${Sophus_LIBRARIES}
         ${NDI_LIB}
         ${ndicapi_LIBRARIES}
         )


