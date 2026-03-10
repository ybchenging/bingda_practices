#!/usr/bin/env python3
import rospy
from std_msgs.msg import String


def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)  # 在ROS日志中输出接收到的消息内容

def listener():
    rospy.init_node('listener', anonymous=True)  # 初始化ROS节点，节点名称为'listener'，anonymous=True表示如果有同名节点会自动添加随机数后缀以区分
    rospy.Subscriber("chatter", String, callback)  # 创建一个订阅者对象，订阅名为'chatter'的话题，消息类型为String，回调函数为callback
    rospy.spin()  # 保持程序持续运行，等待回调函数被调用
if __name__ == '__main__':
    listener()  # 调用listener函数开始订阅消息  