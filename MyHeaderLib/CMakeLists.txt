project(MyHeaderLib CXX)

file(GLOB_RECURSE PublicFiles "Public/*.h")

add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME} PRIVATE ${PublicFiles})

source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/Public" PREFIX "\\Public" FILES ${PublicFiles})

target_include_directories(${PROJECT_NAME} INTERFACE Public)


