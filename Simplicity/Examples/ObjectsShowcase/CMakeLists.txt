add_executable(ObjectsShowcase main.cpp)

target_link_libraries(ObjectsShowcase PRIVATE Simplicity)
target_compile_features(ObjectsShowcase PRIVATE cxx_std_20)

add_custom_command(
	TARGET ObjectsShowcase POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"$<TARGET_FILE:Simplicity>"
	"$<TARGET_RUNTIME_DLLS:ObjectsShowcase>"
    "$<TARGET_FILE_DIR:ObjectsShowcase>"
	COMMAND_EXPAND_LISTS
    COMMENT "Copying necessary dlls to executable directory..."
)

add_custom_command(
    TARGET ObjectsShowcase POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "$<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}/debug/bin,${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}/bin>"
        "$<TARGET_FILE_DIR:ObjectsShowcase>"
    COMMENT "Copying all vcpkg DLLs..."
)