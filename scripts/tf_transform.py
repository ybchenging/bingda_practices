#!/usr/bin/env python3
import rospy
import tf
import math


def tf_transform():
    rospy.init_node('tf_transform')
    br = tf.TransformBroadcaster()
    rate = rospy.Rate(10.0)
    angle = 0   
    rospy.loginfo("tf_transform node has started.")
    while not rospy.is_shutdown():
        x=math.cos(angle)*0.3   
        y=math.sin(angle)*0.3
        z = 0.2
        quat = tf.transformations.quaternion_from_euler(0, 0, angle)
        br.sendTransform((x, y, z), quat, rospy.Time.now(), "talk1", "world")
        br.sendTransform((0.1, 0, 0.2), (0, 0, 0, 1), rospy.Time.now(), "talk2", "world")
        br.sendTransform((x, y, z), (0, 0, 0, 1), rospy.Time.now(), "talk3", "world")
        angle += 0.01
        rate.sleep()
        
        # rate.sleep()

# if __name__ == '__main__':
#     rospy.init_node('tf_transform')
#     br = tf.TransformBroadcaster()
#     rate = rospy.Rate(10.0)
#     while not rospy.is_shutdown():
#         br.sendTransform((0.1, 0, 0.2), (0, 0, 0, 1), rospy.Time.now(), "talk", "world")
#         rate.sleep()


if __name__ == '__main__':
    try:
        tf_transform()
    except rospy.ROSInterruptException:
        pass    