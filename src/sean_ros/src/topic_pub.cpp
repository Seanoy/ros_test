#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "topic_pub");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    geometry_msgs::Twist twist;
    twist.linear.x = 1.0;
    twist.angular.z = 2.0;
    ros::Rate r(10);
    while (ros::ok()) {
        pub.publish(twist);
        ros::spinOnce();
    }
    return 0;
}
