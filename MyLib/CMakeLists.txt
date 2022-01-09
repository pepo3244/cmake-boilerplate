project(MyLib CXX)

file(GLOB_RECURSE PublicFiles "Public/*.h")
file(GLOB_RECURSE PrivateFiles "Private/*.cpp" "Private/*.h")

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PublicFiles} ${PrivateFiles})

# filter setting for Visual Studio
source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/Private" PREFIX "\\Private" FILES ${PrivateFiles})
source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/Public" PREFIX "\\Public" FILES ${PublicFiles})

target_include_directories(${PROJECT_NAME} PUBLIC Public)
target_include_directories(${PROJECT_NAME} PRIVATE Private/include)
target_link_libraries(${PROJECT_NAME} PUBLIC MyHeaderLib)
