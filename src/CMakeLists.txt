include_directories(src)
add_executable(ipfilter main.cpp ip_address_manager.cpp ip_address.cpp helper.cpp search.h)
add_executable(test_ip_filter test_ip_filter.cpp ip_address.cpp helper.cpp helper.h search.h ip_address_manager.cpp)
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
