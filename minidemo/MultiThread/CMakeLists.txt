ADD_EXECUTABLE( PosixCThread PosixCThread.c )
ADD_EXECUTABLE( TaskAssign TaskAssign.c )
ADD_EXECUTABLE( MTMutexLog MTMutexLog.c )
ADD_EXECUTABLE( MultithreadSequencePrint-2 MultithreadSequencePrint-2.c )
ADD_EXECUTABLE( MultithreadSequencePrint MultithreadSequencePrint.c )


TARGET_LINK_LIBRARIES(PosixCThread pthread)
TARGET_LINK_LIBRARIES(TaskAssign pthread)
TARGET_LINK_LIBRARIES(MTMutexLog pthread)
TARGET_LINK_LIBRARIES(MultithreadSequencePrint-2 pthread)
TARGET_LINK_LIBRARIES(MultithreadSequencePrint pthread)



ADD_EXECUTABLE( BoostThreadTiny BoostThreadTiny.cpp )
TARGET_LINK_LIBRARIES(BoostThreadTiny boost_thread)
