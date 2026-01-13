#include "ros/ros.h"
#include "sean_ros/AddInts.h"

bool doReq(sean_ros::AddInts::Request& req,
           sean_ros::AddInts::Response& res)
{
  res.sum = req.num1 + req.num2;
  ROS_INFO("request: num1=%d, num2=%d", req.num1, req.num2);
  ROS_INFO("response: sum=%d", res.sum);
  return true;
}

int main(int argc, char*argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "AddInts_Server");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("AddInts", doReq);
    ROS_INFO("Ready to add two ints.");
    ros::spin();
    return 0;
}