project(Renderer)

if (APPLE)
    search_files(platform Metal)
elseif(WIN32)
    search_files(platform D3D12)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

search_files(common Common)

add_library(${PROJECT_NAME} 
        ${platform_found_sources} 
        ${platform_found_headers}
        ${common_found_sources}
        ${common_found_headers}
    )

target_include_directories(${PROJECT_NAME} PUBLIC 
        ${platform_found_header_dirs}
        ${common_found_header_dirs}
    )
target_include_directories(${PROJECT_NAME} PRIVATE 
        ${common_found_source_dirs}
    )

target_link_libraries(${PROJECT_NAME} PUBLIC Math)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE Metal)
elseif(WIN32)
    search_library(D3D12_LIB D3D12)
    search_library(DXGI_LIB DXGI)
    search_library(D3D_COMPILER_LIB D3DCompiler)

    target_link_libraries(${PROJECT_NAME} PRIVATE ${D3D12_LIB} ${DXGI_LIB} ${D3D_COMPILER_LIB})
endif()
