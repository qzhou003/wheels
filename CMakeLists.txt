project(wheel_detection C CXX)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV 3 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(EXTERNAL_LIBRARIES
	${OpenCV_LIBS}
	${Boost_LIBRARIES}

)

add_executable(hough main.cpp)
target_link_libraries(hough ${EXTERNAL_LIBRARIES})


#add_executable(caffe_txt caffe_txt.cpp)
#target_link_libraries(caffe_txt ${EXTERNAL_LIBRARIES})

#add_executable(list2caffe_txt to_caffe_format.cpp)
#target_link_libraries(list2caffe_txt ${EXTERNAL_LIBRARIES})