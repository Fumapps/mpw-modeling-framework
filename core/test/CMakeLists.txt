include_directories(.)

add_executable(mpw_framework_tests
        FirstSimpleTests.cpp
        LocationTest.cpp
        testdoubles/ActorFake.h
        testdoubles/PropFake.h
        testdoubles/StageFake.h
        util/TestUtils.cpp util/TestUtils.h)
target_link_libraries(mpw_framework_tests mpw_framework_core_lib gtest_main)
add_test(NAME mpw_framework_tests COMMAND mpw_framework_tests WORKING_DIRECTORY $<TARGET_FILE_DIR:mpw_framework_tests>)
