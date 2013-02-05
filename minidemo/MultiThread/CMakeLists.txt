ADD_EXECUTABLE( PosixCThread PosixCThread.c )
ADD_EXECUTABLE( TaskAssign TaskAssign.c )

TARGET_LINK_LIBRARIES(PosixCThread pthread)
TARGET_LINK_LIBRARIES(TaskAssign pthread)                                                                                                    

