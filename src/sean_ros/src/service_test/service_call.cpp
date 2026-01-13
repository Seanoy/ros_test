#include "ros/ros.h"
#include "turtlesim/Spawn.h"
#include <random>
#include <cstdint>
int main(int argc, char*argv[]) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "set_turtle");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    ros::service::waitForService("/spawn");

    turtlesim::Spawn spawn;
    std::random_device rd;  // 非确定性随机数生成器
    spawn.request.x = (float)(rd() % 10);
    spawn.request.y = (float)(rd() % 10);
    spawn.request.theta = 1.57;
    spawn.request.name = "";
    bool flag = client.call(spawn);
    if (flag) {
        ROS_INFO("new turtle name %s", spawn.response.name.c_str());
    } else {
        ROS_INFO("failed to spawn turtle %lf %lf", spawn.request.x, spawn.request.y);
    }
    return 0;
}
