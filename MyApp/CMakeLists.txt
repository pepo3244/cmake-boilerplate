project(MyApp)

file(GLOB_RECURSE PrivateFiles "Private/*.cpp" "Private/*.h")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PrivateFiles})

# filter setting for Visual Studio
source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/Private" PREFIX "\\Private" FILES ${PrivateFiles})

# compile settings
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} 
	PROPERTIES
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)

target_compile_options(${PROJECT_NAME} PRIVATE 
	$<$<CXX_COMPILER_ID:GCC>:-Wall -Wextra -Wno-long-long -pedantic>
	$<$<CXX_COMPILER_ID:MSVC>:/W4>
)

target_link_libraries(${PROJECT_NAME} PRIVATE MyLib)
