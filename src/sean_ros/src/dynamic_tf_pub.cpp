#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

void doPose(const turtlesim::Pose::ConstPtr& pose) {
    static tf2_ros::TransformBroadcaster boardcaster;
    geometry_msgs::TransformStamped ts;
    ts.header.seq = 100;
    ts.header.frame_id = "world";
    ts.child_frame_id = "turtle1";
    ts.header.stamp = ros::Time::now();
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0.0;
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();
    boardcaster.sendTransform(ts);
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "dynamic_tf_pub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 10, doPose);
    ros::spin();
    return 0;
}
