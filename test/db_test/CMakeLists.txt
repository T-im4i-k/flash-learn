add_executable(db_test db_test.cpp)
target_link_libraries(db_test PRIVATE db)

add_test(NAME db_test_run COMMAND db_test)