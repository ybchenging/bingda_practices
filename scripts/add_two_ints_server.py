#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from bingda_prictices.msg import student  # 导入我们自己定义的消息类型
from bingda_prictices.srv import addtwoints, addtwointsResponse  # 导入我们自己定义的服务类型和服务响应类型

def handle_add_two_ints(req):
    sum = req.a + req.b
    rospy.loginfo("Adding %d and %d, result is %d", req.a, req.b, sum)
    return addtwointsResponse(sum)  # 返回结果

def add_two_ints_server():
    rospy.init_node('add_two_ints_server')  # 初始化ROS节点
    s = rospy.Service('add_two_ints', addtwoints, handle_add_two_ints)  # 创建服务，服务名称为add_two_ints，服务类型为addtwoints，回调函数为handle_add_two_ints
    rospy.loginfo("Ready to add two ints.")  # 打印日志信息
    rospy.spin()  # 保持节点运行

if __name__ == "__main__":
    add_two_ints_server()  # 启动服务服务器
