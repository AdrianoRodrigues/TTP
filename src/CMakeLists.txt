######################################################################################
### 1) Include the sources
######################################################################################

include_directories(${EO_INCLUDE_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

######################################################################################

######################################################################################
### 2) Define your target(s): just the tsp lib here
######################################################################################

set(TTP_LIB_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

set(LIBRARY_OUTPUT_PATH ${TTP_LIB_OUTPUT_PATH})

set(TTP_SOURCES railway.h 				
				railway.cpp   
				scheduling.h 
				schedulingDecoder.h
				schedulingDecoder.cpp
				schedulingEval.h
				schedulingEval.cpp
				schedulingInit.h
				schedulingInit.cpp  
				schedulingSwap.h
				schedulingSwap.cpp
				schedulingValid.h
				schedulingValid.cpp
				schedulingXover.h
				schedulingXover.cpp)
				
add_library(lttp STATIC ${TTP_SOURCES})  		
######################################################################################
