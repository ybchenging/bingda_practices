#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from bingda_prictices.msg import student  # 导入我们自己定义的消息类型



def msg_sub():  # 定义一个函数，名字叫msg_sub，用来订阅消息并处理接收到的消息
    rospy.init_node('msg_sub', anonymous=True)  # 初始化ROS节点，节点名称为'msg_sub'，anonymous=True表示如果有同名节点会自动添加随机数后缀以区分
    rospy.Subscriber("student_info", student, callback)  # 创建一个订阅者对象，订阅名为'student_info'的话题，消息类型为student，回调函数为callback
    rospy.spin()  # 保持程序持续运行，等待回调函数被调用


def callback(data): # 定义一个回调函数，名字叫callback，当接收到消息时会调用这个函数，参数data就是接收到的消息对象
    rospy.loginfo("Received student info: %s %s, age: %d, score: %d", 
                  data.firstname, data.lastname, data.age, data.score)  # 在ROS日志中输出接收到的消息内容
    


if __name__ == '__main__':
    msg_sub()  # 调用msg_sub函数开始订阅消息
