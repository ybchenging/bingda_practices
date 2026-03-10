#include <ros/ros.h>
#include <std_msgs/String.h>


int main(int argc, char **argv)//ROS节点的入口函数
{
    ros::init(argc, argv, "talker");//初始化ROS节点，节点名称为talker
    ros::NodeHandle n;//创建一个NodeHandle对象，负责与ROS系统进行通信
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);//创建一个Publisher对象，发布消息到名为"chatter"的主题，队列大小为1000
    ros::Rate loop_rate(10);//设置循环频率为10Hz

    int count = 0;//定义一个计数器，用于生成消息内容
    while (ros::ok())//ROS节点的主循环，持续运行直到节点被关闭
    {
        std_msgs::String msg;// 创建一个String类型的消息对象
        std::stringstream ss;// 创建一个字符串流对象，用于构建消息内容
        ss << "hello world " << count;// 将字符串 "hello world " 和计数器的值拼接成消息内容
        msg.data = ss.str();// 将构建好的消息内容赋值给消息对象的data成员

        ROS_INFO("%s", msg.data.c_str());// 输出日志信息，显示发布的消息内容

        chatter_pub.publish(msg);// 发布消息到主题"chatter"

        ros::spinOnce();// 处理ROS回调函数，确保节点能够响应订阅者的请求

        loop_rate.sleep();// 按照设置的循环频率休眠，控制发布消息的频率
        ++count;
    }

    return 0;
}