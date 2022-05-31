message("WITH_SERVER_TESTS = ${WITH_SERVER_TESTS}")
message("WITH_CLIENT_TESTS = ${WITH_CLIENT_TESTS}")

if (WITH_SERVER_TESTS)
    add_subdirectory(test_server)
endif()

if (WITH_CLIENT_TESTS)
    add_subdirectory(test_client)
endif()