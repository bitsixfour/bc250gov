cmake_minimum_required(VERSION 3.16)
project(bc250gov CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(bc250gov
    src/main.cpp
    src/config.cpp
    src/idle/policy.cpp
    src/smu/cmd.cpp
    src/smu/status.cpp
    src/smu/transport.cpp
    src/smu/smu.cpp
)

target_include_directories(bc250gov PRIVATE src)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBDRM REQUIRED IMPORTED_TARGET libdrm)
pkg_check_modules(LIBDRM_AMDGPU REQUIRED IMPORTED_TARGET libdrm_amdgpu)
pkg_check_modules(YAML_CPP REQUIRED IMPORTED_TARGET yaml-cpp)
target_link_libraries(bc250gov PRIVATE PkgConfig::YAML_CPP)
target_link_libraries(bc250gov PRIVATE PkgConfig::LIBDRM)
target_link_libraries(bc250gov PRIVATE PkgConfig::LIBDRM_AMDGPU)
