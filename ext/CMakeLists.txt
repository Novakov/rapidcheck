if (RC_ENABLE_TESTS OR RC_ENABLE_CATCH)
  add_library(catch INTERFACE)
  target_include_directories(catch INTERFACE catch/include)
endif()

if (RC_ENABLE_GMOCK AND RC_ENABLE_TESTS)
  if (NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/gmock/CMakeLists.txt")
    execute_process(
      COMMAND "sh" "get_gmock.sh"
      WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")
  endif()

  # On Windows, gmock/gtest defaults to static CRT which is not compatible
  # with the way RapidCheck is currently built
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  add_subdirectory(gmock)
endif()

if (RC_ENABLE_BOOST AND RC_ENABLE_TESTS)
  if (NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/boost")
    execute_process(
      COMMAND "sh" "get_boost.sh"
      WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")
  endif()
  add_library(boost INTERFACE)
  target_include_directories(boost INTERFACE boost)
endif()
