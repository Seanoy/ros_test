#include "ros/ros.h"
#include "sean_ros/AddInts.h"

int main(int argc, char*argv[]){
    setlocale(LC_ALL, "");
    if (argc != 3){
        ROS_ERROR("usage: add_two_ints_client X Y");
        return 1;
    }

    ros::init(argc, argv, "AddInts_Client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<sean_ros::AddInts>("AddInts");
    ros::service::waitForService("AddInts");

    sean_ros::AddInts srv;
    srv.request.num1 = atoll(argv[1]);
    srv.request.num2 = atoll(argv[2]);

    bool flag = client.call(srv);
    if (flag){
        ROS_INFO("Sum: %d", srv.response.sum);
    }
    else{
        ROS_ERROR("Failed to call service AddInts");
        return 1;
    }
    
    return 0;
}