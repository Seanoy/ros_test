#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/buffer.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/PointStamped.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "sub_frames");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    ros::Rate rate(1);
    while (ros::ok()) {
        try
        {
        geometry_msgs::TransformStamped tfs = buffer.lookupTransform("son2", "son1", ros::Time(0));
        ROS_INFO("Son1 相对于 Son2 的坐标关系:父坐标系ID=%s 子坐标系ID=%s x=%.2f,y=%.2f,z=%.2f",
            tfs.header.frame_id.c_str(),
            tfs.child_frame_id.c_str(),
            tfs.transform.translation.x,
            tfs.transform.translation.y,
            tfs.transform.translation.z
        );

        geometry_msgs::PointStamped ps;
        ps.header.frame_id = "son1";
        ps.header.stamp = ros::Time::now();
        ps.point.x = 1.0;
        ps.point.y = 2.0;
        ps.point.z = 3.0;

        geometry_msgs::PointStamped psAtSon2;
        psAtSon2 = buffer.transform(ps,"son2");
        ROS_INFO("在 Son2 中的坐标:x=%.2f,y=%.2f,z=%.2f",
                psAtSon2.point.x,
                psAtSon2.point.y,
                psAtSon2.point.z
                );
        }
        catch(const std::exception& e)
        {
            ROS_INFO("error:%s",e.what());
        }
        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
