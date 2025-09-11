add_executable(BasicWindow main.cpp)

# Link your lib (transitively pulls all dependencies)
target_link_libraries(BasicWindow PRIVATE Simplicity)

# Optional: require C++20 here as well
target_compile_features(BasicWindow PRIVATE cxx_std_20)