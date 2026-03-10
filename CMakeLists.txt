cmake_minimum_required(VERSION 3.0.2)
project(bingda_prictices)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation #自定义消息需要这个组件
  tf
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  student.msg
  #Message2.msg
) # 生成消息文件，student.msg是我们自己定义的消息文件，Message2.msg是一个示例，可以删除或者替换成你自己的消息文件

# Generate services in the 'srv' folder
add_service_files(
  FILES
  addtwoints.srv
  # Service2.srv
)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)  # 生成消息时需要依赖std_msgs包，因为我们在student.msg中使用了std_msgs中的string类型

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES bingda_prictices
 CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
#  DEPENDS system_lib
)# 生成catkin包配置文件，告诉其他包这个包依赖roscpp、rospy和std_msgs这三个包，如果有其他依赖的包也要在这里列出来
#message_runtime的作用是告诉其他包这个包生成了消息文件，其他包需要依赖message_runtime才能使用这些消息文件


###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/bingda_prictices.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
# add_executable(${PROJECT_NAME}_node src/bingda_prictices_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# catkin_install_python(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_bingda_prictices.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
add_executable(talker src/talker.cpp) # 创建一个可执行文件，名字叫talker，源文件是src/talker.cpp
target_link_libraries(talker
  ${catkin_LIBRARIES}
)  # 将talker可执行文件链接到catkin库，这样它就可以使用ROS的功能了

add_executable(listener src/listener.cpp) # 创建一个可执行文件，名字叫listener，源文件是src/listener.cpp
target_link_libraries(listener
  ${catkin_LIBRARIES}
)  # 将listener可执行文件链接到catkin库，这样它就可以使用ROS的功能了


add_executable(msg_pub src/msg_pub.cpp) # 创建一个可执行文件，名字叫msg_pub，源文件是src/msg_pub.cpp
add_dependencies(msg_pub bingda_prictices_generate_messages_cpp) # 添加msg_pub可执行文件对生成消息代码的依赖，这样在编译msg_pub之前会先生成消息代码，确保msg_pub可以使用我们定义的消息类型
target_link_libraries(msg_pub
  ${catkin_LIBRARIES}
)  # 将msg_pub可执行文件链接到catkin库，这样它就可以使用ROS的功能了


add_executable(msg_sub src/msg_sub.cpp) # 创建一个可执行文件，名字叫msg_sub，源文件是src/msg_sub.cpp
add_dependencies(msg_sub bingda_prictices_generate_messages_cpp) # 添加msg_sub可执行文件对生成消息代码的依赖，这样在编译msg_sub之前会先生成消息代码，确保msg_sub可以使用我们定义的消息类型
target_link_libraries(msg_sub
  ${catkin_LIBRARIES}
)  # 将msg_sub可执行文件链接到catkin库，这样它就可以使用ROS的功能了


add_executable(add_two_ints_server src/add_two_ints_server.cpp) # 创建一个可执行文件，名字叫add_two_ints_server，源文件是src/add_two_ints_server.cpp
add_dependencies(add_two_ints_server bingda_prictices_generate_messages_cpp) # 添加add_two_ints_server可执行文件对生成消息代码的依赖，这样在编译add_two_ints_server之前会先生成消息代码，确保add_two_ints_server可以使用我们定义的消息类型
target_link_libraries(add_two_ints_server
  ${catkin_LIBRARIES}
)  # 将add_two_ints_server可执行文件链接到catkin库，这样它就可以使用ROS的功能了

add_executable(add_two_ints_client src/add_two_ints_client.cpp) # 创建一个可执行文件，名字叫add_two_ints_client，源文件是src/add_two_ints_client.cpp
add_dependencies(add_two_ints_client bingda_prictices_generate_messages_cpp) # 添加add_two_ints_client可执行文件对生成消息代码的依赖，这样在编译add_two_ints_client之前会先生成消息代码，确保add_two_ints_client可以使用我们定义的消息类型
target_link_libraries(add_two_ints_client
  ${catkin_LIBRARIES}
)  # 将add_two_ints_client可执行文件链接到catkin库，这样它就可以使用ROS的功能了



add_executable(tf_transform src/tf_transform.cpp) # 创建一个可执行文件，名字叫tf_transform，源文件是src/tf_transform.cpp
add_dependencies(tf_transform bingda_prictices_generate_messages_cpp) # 添加tf_transform可执行文件对生成消息代码的依赖，这样在编译tf_transform之前会先生成消息代码，确保tf_transform可以使用我们定义的消息类型
target_link_libraries(tf_transform
  ${catkin_LIBRARIES}
)  # 将tf_transform可执行文件链接到catkin库，这样它就可以使用ROS的功能了