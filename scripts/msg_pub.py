#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from bingda_prictices.msg import student  # 导入我们自己定义的消息类型  

def msg_pub():  
    pub = rospy.Publisher('student_info', student, queue_size=10)  # 创建一个发布者对象，发布到名为'student_info'的话题，消息类型为student，队列大小为10
    rospy.init_node('msg_pub', anonymous=True)  # 初始化ROS节点，节点名称为'msg_pub'，anonymous=True表示如果有同名节点会自动添加随机数后缀以区分
    rate = rospy.Rate(5)  # 设置循环频率为5Hz
    while not rospy.is_shutdown():  # 当ROS没有关闭时持续循环
        student_msg = student()  # 创建一个student消息对象
        student_msg.firstname = "John"  # 设置消息的firstname字段
        student_msg.lastname = "Doe"  # 设置消息的lastname字段
        student_msg.age = 20  # 设置消息的age字段
        student_msg.score = 85  # 设置消息的score字段
        rospy.loginfo("Publishing student info: %s %s, age: %d, score: %d", 
                      student_msg.firstname, student_msg.lastname, 
                      student_msg.age, student_msg.score)  # 在ROS日志中输出要发布的消息内容
        pub.publish(student_msg)  # 发布消息到'student_info'话题
        rate.sleep()  # 按照设定的频率休眠

if __name__ == '__main__':
    try:
        msg_pub()  # 调用msg_pub函数开始发布消息
    except rospy.ROSInterruptException:  # 捕获ROS中断异常
        pass  # 如果ROS被中断，捕获异常并退出程序   