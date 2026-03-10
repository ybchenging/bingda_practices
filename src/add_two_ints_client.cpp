#include <ros/ros.h>
#include <bingda_prictices/addtwoints.h>//包含服务消息头文件    

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");//初始化ROS节点，节点名称为"add_two_ints_client"
  ros::NodeHandle n;//创建一个节点句柄

  ros::ServiceClient client = n.serviceClient<bingda_prictices::addtwoints>("add_two_ints");//创建一个服务客户端，服务类型为bingda_prictices::addtwoints，服务名称为"add_two_ints"
  bingda_prictices::addtwoints srv;//创建一个服务对象

  srv.request.a = atoll(argv[1]);//将命令行参数转换为整数，并赋值给请求消息的a字段
  srv.request.b = atoll(argv[2]);//将命令行参数转换为整数，并赋值给请求消息的b字段

  if (client.call(srv))//调用服务，如果调用成功
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);//输出响应消息中的sum字段
  }
  else//如果调用失败
  {
    ROS_ERROR("Failed to call service add_two_ints");//输出错误信息
    return 1;
  }

  return 0;
}