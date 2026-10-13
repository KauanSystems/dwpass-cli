# program/src/cli/CMakeLists.txt

if (MSVC)
    add_compile_options(/utf-8 /EHsc)
endif()

add_executable(${PROJECT_NAME}
	main.cpp
	command_table/command_table.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	${PROJECT_NAME}_lib_command
	${PROJECT_NAME}_lib_logic
)
