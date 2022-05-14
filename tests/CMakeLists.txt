if (WITH_SERVER_TESTS)
    add_subdirectory(test_server)
endif()

if (WITH_CLIENT_TESTS)
    add_subdirectory(test_client)
endif()