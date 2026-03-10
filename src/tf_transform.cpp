#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h> // 包含tf变换数据类型的头文件
#include <math.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "tf_transform");
  ros::NodeHandle node;

  tf::TransformBroadcaster br; //创建一个tf变换广播器对象
  tf::Transform transform;//创建一个tf变换对象
  ros::Rate rate(10.0);

  float angle = 0.0;
  float x = 0.0;
  float y = 0.0;
  float z = 0.0;

  ROS_INFO("tf_transform node started, broadcasting transforms...");

  while (node.ok()){
    x=sin(angle ) * 0.3; 
    y=cos(angle ) * 0.3; 
    z=0.2; // z坐标保持不变
    br.sendTransform(tf::StampedTransform(
    tf::Transform(/*tf::Quaternion(0, 0, angle)*/tf::createQuaternionFromRPY(0, 0, angle), tf::Vector3(x, y, z)), 
    ros::Time::now(), "world", "talk")); // 发布坐标变换，父坐标系为"world"，子坐标系为"talk"
    
    br.sendTransform(tf::StampedTransform(
    tf::Transform(tf::Quaternion(0, 0, 0,1) /*tf::createQuaternionFromRPY(0, 0, angle)*/, tf::Vector3(x, y, z)), 
    ros::Time::now(), "world", "talk1")); // 发布坐标变换，父坐标系为"world"，子坐标系为"talk"
    
    
    
    
    
    angle += 0.01; // 每次循环增加0.01度
rate.sleep(); // 按照设定的频率休眠，控制发布变换的频率


    // transform.setOrigin( tf::Vector3(x, y, z) );// 设置变换的平移部分，使其在x-y平面上以0.1的半径绕z轴旋转
    // angle += 10.0; // 每次循环增加10度
    // if (angle >= 360.0) {
    //   angle -= 360.0; // 保持角度在0-360度范围内
    // }
    // tf::Quaternion q;// 创建一个四元数对象
    // q.setRPY(0, 0, 0);// 设置变换的旋转部分，这里设置为无旋转
    // transform.setRotation(q);// 将四元数设置为变换的旋转部分
    // br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "talk"));// 发布坐标变换，父坐标系为"world"，子坐标系为"talk"
    // rate.sleep();   

  }
  return 0;
};