#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;
  ros::Publisher chatter_pub1 = n.advertise<std_msgs::String>("chatter1", 1000);

  ros::Rate loop_rate(10);

  int count = 10;
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;

    if(count != 0){
        ss << count;
    }
    else if (count == 0 ){
        ss << count;
    }
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());
    chatter_pub1.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    --count;

  }


  return 0;
}
