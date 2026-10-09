# program/src/cli/CMakeLists.txt

add_executable(${PROJECT_NAME}
	main.cpp
	command_table/command_table.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	${PROJECT_NAME}_lib_command
	${PROJECT_NAME}_lib_logic
)
