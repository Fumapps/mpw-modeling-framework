project(mpw_framework_core)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src/framework)
add_subdirectory(src/generated)
add_subdirectory(src/impl)
set(SRCS ${GEN_SRCS} ${IMPL_SRCS} ${FRAMEWORK_SRCS})

add_library(mpw_framework_core_lib STATIC ${SRCS})

# Define facade include directories
set(FACADE_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/facade ${CMAKE_CURRENT_SOURCE_DIR}/src/facade/generated
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/generated
        ${CMAKE_CURRENT_SOURCE_DIR}/src/datatypes ${CMAKE_CURRENT_SOURCE_DIR}/src/datatypes/generated)
set_property(TARGET mpw_framework_core_lib PROPERTY FACADE_INCLUDES ${FACADE_INCLUDES}) # attach to target to make the property retrievable for other projects

target_include_directories(mpw_framework_core_lib PUBLIC src/basetypes)
target_include_directories(mpw_framework_core_lib PUBLIC src/basetypes/generated)
target_include_directories(mpw_framework_core_lib PUBLIC src/commands)
target_include_directories(mpw_framework_core_lib PUBLIC src/commands/generated)
target_include_directories(mpw_framework_core_lib PUBLIC src/mpw)
target_include_directories(mpw_framework_core_lib PUBLIC src/mpw/generated)
target_include_directories(mpw_framework_core_lib PUBLIC src/viewmodel)
target_include_directories(mpw_framework_core_lib PUBLIC src/viewmodel/generated)
target_include_directories(mpw_framework_core_lib PUBLIC src/impl)
target_include_directories(mpw_framework_core_lib PUBLIC ${FACADE_INCLUDES})

## Setup GTEST

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(test)
