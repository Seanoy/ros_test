#include "ros/ros.h"
#include "actionlib/server/simple_action_server.h"
#include "action_test/AddIntsAction.h"

typedef actionlib::SimpleActionServer<action_test::AddIntsAction> Server;

void cb(const action_test::AddIntsGoalConstPtr &goal, Server* server) {
    // get goal
    int num = goal->num;
    ROS_INFO("goal %d", num);
    int result = 0;
    action_test::AddIntsFeedback feedback;
    ros::Rate rate(10);
    for (int i = 1; i <= num; i++) {
        result += i;
        feedback.progress_bar = i / (double)num;
        server->publishFeedback(feedback);
        rate.sleep();
    }
    action_test::AddIntsResult r;
    r.result = result;
    server->setSucceeded(r);
    ROS_INFO("result: %d", r.result);
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL,"");
    ROS_INFO("action server");
    ros::init(argc, argv, "AddInts_server");
    ros::NodeHandle nh;
    Server server(nh, "addInts", boost::bind(&cb, _1, &server), false);
    server.start();

    ros::spin();
    return 0;
}
