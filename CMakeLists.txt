# Set min. cmake version
cmake_minimum_required (VERSION 3.12.4) 

# name of project 
#project (cmake VERSION 0.0.$ENV{PROJECT_VERSION_PATCH})
project (helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})


find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

# Add dir with "spdlog/spdlog.h" (Example for git clone spdlog)
include_directories(spdlog/include)

# Add file to compile (Bin source)
add_executable(helloworld_cli main.cpp)

add_library(helloworld lib.cpp)

add_executable(test_version test_version.cpp)

# Set compile options
set_target_properties(PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(helloworld_cli
    helloworld
    Threads::Threads
)

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    helloworld
)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

###################################### Need read manuals ######################
set(CPACK_PACKAGE_CONTACT s.i.v.892@gmail.com)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(helloworld_tests test_version)
