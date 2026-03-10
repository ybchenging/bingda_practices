#include "ros/ros.h"
#include "bingda_prictices/student.h" // 包含我们自己定义的消息类型

int main(int argc, char **argv) // ROS节点的入口函数
{
    ros::init(argc, argv, "msg_pub"); // 初始化ROS节点，节点名称为msg_pub
    ros::NodeHandle n; // 创建一个NodeHandle对象，负责与ROS系统进行通信
    ros::Publisher pub = n.advertise<bingda_prictices::student>("student_info", 1000); // 创建一个Publisher对象，发布名为"student_info"的主题，消息类型是bingda_prictices::student，队列大小为1000

    ros::Rate loop_rate(10); // 设置循环频率为10Hz

    while (ros::ok()) // 循环发布消息，直到ROS节点被关闭
    {
        bingda_prictices::student msg; // 创建一个消息对象，类型是我们自己定义的bingda_prictices::student
        msg.firstname = "John"; // 设置消息中的firstname字段
        msg.lastname = "Doe"; // 设置消息中的lastname字段
        msg.age = 20; // 设置消息中的age字段
        msg.score = 85; // 设置消息中的score字段

        pub.publish(msg); // 发布消息到"student_info"主题

        ros::spinOnce(); // 处理回调函数，如果有的话

        loop_rate.sleep(); // 按照设置的频率休眠
    }

    return 0;
}