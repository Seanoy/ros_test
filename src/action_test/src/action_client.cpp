
#include "ros/ros.h"
#include "actionlib/client/simple_action_client.h"
#include "action_test/AddIntsAction.h"

typedef actionlib::SimpleActionClient<action_test::AddIntsAction> Client;

void done_cb(const actionlib::SimpleClientGoalState &state, 
    const action_test::AddIntsResultConstPtr &result) {
        if (state.state_ == state.SUCCEEDED){
            ROS_INFO("result: %d", result->result);
        } else {
            ROS_INFO("action failed");
        }
}

void active_cb() {
    ROS_INFO("server activated");
}

void feedback_cb(const action_test::AddIntsFeedbackConstPtr &feedback) {
    ROS_INFO("current progress %.2f", feedback->progress_bar);
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "AddInts_client");
    ros::NodeHandle nh;
    Client client(nh, "addInts", true);
    client.waitForServer();

    action_test::AddIntsGoal goal;
    goal.num = 10;
    client.sendGoal(goal,&done_cb, &active_cb, &feedback_cb);
    ros::spin();
    return 0;
}
