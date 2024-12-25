#include "ros/ros.h"
#include "std_msgs/String.h"
using namespace std;    

string omni, front;

void chatterCallback_omni(const std_msgs::String::ConstPtr& msg)
{
  omni = msg->data;
    ROS_INFO("From Cam Omni: [%s]", omni.c_str());
  
}
void chatterCallback_front(const std_msgs::String::ConstPtr& msg2)
{
  front = msg2->data;

    ROS_INFO("From Cam Front: [%s]", front.c_str());
  
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub_omni = n.subscribe("chatter1", 1000, chatterCallback_omni);
  ros::Subscriber sub_front = n.subscribe("chatter2", 1000, chatterCallback_front);

  ros::spin();

  return 0;
}