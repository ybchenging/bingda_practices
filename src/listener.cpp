#include "ros/ros.h"
#include "std_msgs/String.h"



void chatterCallback(const std_msgs::String::ConstPtr& msg) // 定义回调函数，参数是一个指向接收到的消息的智能指针
{
    ROS_INFO("I heard: [%s]", msg->data.c_str()); // 输出日志信息，显示接收到的消息内容
}

int main(int argc, char **argv) // ROS节点的入口函数
{
    ros::init(argc, argv, "listener"); // 初始化ROS节点，节点名称为listener
    ros::NodeHandle n; // 创建一个NodeHandle对象，负责与ROS系统进行通信
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback); // 创建一个Subscriber对象，订阅名为"chatter"的主题，队列大小为1000，回调函数为chatterCallback

    ros::spin(); // 进入循环，等待回调函数被调用

    return 0;
}