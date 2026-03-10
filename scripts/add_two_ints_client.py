#!/usr/bin/env python3
import sys
import rospy
from bingda_prictices.srv import addtwoints  # 导入我们自己定义

def add_two_ints_client(x, y):
    rospy.wait_for_service('add_two_ints')  # 等待服务可用
    try:
        add_two_ints = rospy.ServiceProxy('add_two_ints', addtwoints)  # 创建服务代理 #addtwoints是服务名称，addtwoints是服务类型
        resp = add_two_ints(x, y)  # 调用服务，传入参数x和y
        return resp.sum  # 返回结果
    except rospy.ServiceException as e:
        print("Service call failed: %s" % e)

if __name__ == "__main__":
    if len(sys.argv) != 3: # 检查命令行参数是否正确
        print("Usage: add_two_ints_client.py [x y]")
        sys.exit(1)
    x = int(sys.argv[1])  # 从命令行参数获取第一个整数
    y = int(sys.argv[2])  # 从命令行参数获取第二个整数
    print("Requesting %d + %d" % (x, y))
    result = add_two_ints_client(x, y)  # 调用客户端函数，获取结果
    print("%d + %d = %d" % (x, y, result))  # 打印结果

