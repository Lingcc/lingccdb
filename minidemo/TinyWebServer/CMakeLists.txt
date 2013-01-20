
ADD_EXECUTABLE(TinyWebServer tiny.c csapp.c)

TARGET_LINK_LIBRARIES(TinyWebServer pthread)
