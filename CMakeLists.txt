cmake_minimum_required(VERSION 3.16)
IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
ELSE()
    set(ENV{TRAVIS_BUILD_NUMBER} 1)
ENDIF()
project(ipfilter, VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
set(CMAKE_CXX_STANDARD 14)
include_directories(src)
add_executable(ipfilter src/main.cpp src/ip_address_manager.cpp src/ip_address.cpp src/helper.cpp)
add_executable(test_ip_filter src/test_ip_filter.cpp src/ip_address.cpp src/helper.cpp src/ip_address_manager.cpp)
set_target_properties(test_ip_filter PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )
target_link_libraries(test_ip_filter ${Boost_LIBRARIES})
enable_testing()
add_test(test_ip_filter test_suite)

install(TARGETS ipfilter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

