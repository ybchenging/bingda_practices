#include <ros/ros.h>
#include "bingda_prictices/student.h"

void studentInfoCallback(const bingda_prictices::student::ConstPtr& msg) // 定义一个回调函数，参数是一个指向我们定义的消息类型的常量指针
{
    ROS_INFO("Received student info: %s %s, age: %d, score: %d", msg->firstname.c_str(), msg->lastname.c_str(), msg->age, msg->score); // 打印接收到的消息内容，使用ROS_INFO宏来输出日志信息
}

int main(int argc, char **argv) // ROS节点的入口函数
{
    ros::init(argc, argv, "msg_sub"); // 初始化ROS节点，节点名称为msg_sub
    ros::NodeHandle n; // 创建一个NodeHandle对象，负责与ROS系统进行通信
    ros::Subscriber sub = n.subscribe("student_info", 1000, studentInfoCallback); // 创建一个Subscriber对象，订阅名为"student_info"的主题，队列大小为1000，回调函数是studentInfoCallback

    ros::spin(); // 进入循环，等待回调函数被调用

    return 0;
}