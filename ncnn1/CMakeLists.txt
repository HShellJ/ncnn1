# CMakeList.txt: ncnn1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (ncnn1 "ncnn1.cpp" "ncnn1.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ncnn1 PROPERTY CXX_STANDARD 20)
endif()

# 1. 头文件路径（注意修正拼写：IB_FORC → LIB_FORC）
target_include_directories(ncnn1 PRIVATE "D:/LIB_FORC/ncnn/x64/include")

# 2. 库文件路径（指向存放 .lib 的 lib 文件夹，用 / 代替 \）
target_link_directories(ncnn1 PRIVATE "D:/LIB_FORC/ncnn/x64/lib")

# 3. 链接 ncnn 库（指定库名称，比如 ncnn.lib 对应 "ncnn"）
target_link_libraries(ncnn1 PRIVATE ncnn)
target_link_libraries(ncnn1 PRIVATE glslang)

#找到OpenCV
find_package(OpenCV REQUIRED)

message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS         = ${OpenCV_LIBS}")

target_include_directories(ncnn1 PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(ncnn1 PRIVATE ${OpenCV_LIBS})

# TODO: 如有需要，请添加测试并安装目标。
