# CMakeLists.txt in Test dir
# Make sure the compiler can find include files from our Hello Library.
INCLUDE_DIRECTORIES( ${HelloDB_SOURCE_DIR}/minidemo/hello )

# Add binary called "helloWorld" that is build from the source file 'test.cc'
# The extension is automatically found.
ADD_EXECUTABLE(helloWorld test)


# Link the executable to the Hello Library.
TARGET_LINK_LIBRARIES(helloWorld Hello)
