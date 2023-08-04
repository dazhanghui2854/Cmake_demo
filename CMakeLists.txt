cmake_minimum_required(VERSION 3.12)
project(YourProjectName)


# 输出源代码目录
message("当前源代码目录： ${CMAKE_CURRENT_SOURCE_DIR}")
# 输出构建目录
message("当前构建目录： ${CMAKE_CURRENT_BINARY_DIR}")

#debug版本
SET(CMAKE_BUILD_TYPE 'Debug')

#需要编译的文件所需要的头文件路径
set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/modules/hello/include
                 ${CMAKE_CURRENT_SOURCE_DIR}/modules/caculate/include
)

#需要编译的源文件路径
set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/modules/hello/src
             ${CMAKE_CURRENT_SOURCE_DIR}/modules/caculate/src
)



set(PROJECT_SRC)#设置变量为空
set(SOURCES)

#统一管理头文件路径
include_directories(${INCLUDE_PATH})
foreach(_var ${SRC_PATH}) ##遍历SRC_PATH变量
    aux_source_directory(${_var} SOURCES) ##将当前_var目录下的所有源文件都添加到 SOURCES变量中
    message("当前变量是：${_var}")
endforeach()





message("SOURCES: $(SOURCES)")

#将所有source的源文件编译成一个so
add_library(testlib SHARED ${SOURCES})


add_executable(sonia ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

#可执行程序需要链接的库(编译的库 + 三方库)
target_link_libraries(sonia
        testlib
        pthread
        m
        rt
        dl)


# #打印所有头文件路径
# foreach(fruit ${INCLUDE_PATH})
#   message("PATH IS： ${fruit}")
# endforeach()

# #打印所有源文件路径
# foreach(fruit ${SRC_PATH})
#   message("SRC_PATH IS： ${fruit}")
# endforeach()


# #将所有自己的逻辑.cpp 构造成一个so
# add_library( # Specifies the name of the library.
#         native
#         # Sets the library as a shared library.
#         SHARED
#         ${PROJECT_SRC}
#         )

# find_library( log-lib log )


# # 查找并存储 pthread 库的路径
# # find_library(PTHREAD_LIB pthread)


# #mas_lib库运行所需要的依赖库-建立依赖关系
# target_link_libraries(mas_lib
#         xlogger
#         mas_grpc_proto
#         algbox3
#         pthread
#         opencv_core
#         opencv_imgproc
#         opencv_imgcodecs
#         opencv_freetype
#         minizip
#         z
#         m
#         rt
#         dl)

# # main函数编译的a.out程序
# add_executable(mas ${CMAKE_CURRENT_SOURCE_DIR}/modules/main.cpp)

# #a.out程序依赖的所有库
# target_link_libraries(mas
#         mas_lib
#         mas_grpc_proto
#         breakpad
#         blkid
#         udev
#         pthread
#         m
#         rt
#         dl)