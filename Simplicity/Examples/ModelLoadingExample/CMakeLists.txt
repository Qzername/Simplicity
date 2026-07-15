add_executable(ModelLoadingExample main.cpp)

target_link_libraries(ModelLoadingExample PRIVATE Simplicity)
target_compile_features(ModelLoadingExample PRIVATE cxx_std_20)

add_custom_command(
	TARGET ModelLoadingExample POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"$<TARGET_FILE:Simplicity>"
	"$<TARGET_RUNTIME_DLLS:ModelLoadingExample>"
    "$<TARGET_FILE_DIR:ModelLoadingExample>"
	COMMAND_EXPAND_LISTS
    COMMENT "Copying necessary dlls to executable directory..."
)

add_custom_command(
    TARGET ModelLoadingExample POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "$<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}/debug/bin,${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}/bin>"
        "$<TARGET_FILE_DIR:ModelLoadingExample>"
    COMMENT "Copying all vcpkg DLLs..."
)