#!/usr/bin/env python3 
import rospy
from std_msgs.msg import String


def talker():
    pub = rospy.Publisher('chatter', String, queue_size=10)  # 创建一个发布者对象，发布到名为'chatter'的话题，消息类型为String，队列大小为10
    rospy.init_node('talker', anonymous=True)  # 初始化ROS节点，节点名称为'talker'，anonymous=True表示如果有同名节点会自动添加随机数后缀以区分
    rate = rospy.Rate(10)  # 设置循环频率为10Hz
    while not rospy.is_shutdown():  # 当ROS没有关闭时持续循环
        hello_str = "hello world %s" % rospy.get_time()  # 创建要发布的消息内容，包含当前时间
        rospy.loginfo(hello_str)  # 在ROS日志中输出消息内容
        pub.publish(hello_str)  # 发布消息到'chatter'话题
        rate.sleep()  # 按照设定的频率休眠

if __name__ == '__main__':
    try:
        talker()  # 调用talker函数开始发布消息
    except rospy.ROSInterruptException: #捕获ROS中断异常
        pass  # 如果ROS被中断，捕获异常并退出程序   