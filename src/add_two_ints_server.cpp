#include <ros/ros.h>
#include <bingda_prictices/addtwoints.h>//包含服务消息头文件


bool add(bingda_prictices::addtwoints::Request &req,
         bingda_prictices::addtwoints::Response &res)//服务回调函数
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_ints", add);//创建一个服务服务器，服务名称为"add_two_ints"，回调函数为add
  ROS_INFO("Ready to add two ints.");//输出日志信息
  ros::spin();//循环等待回调函数

  return 0;
}

