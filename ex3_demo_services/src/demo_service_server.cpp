//This code is the ROS service server code which will receive the integer from service client

#include "ros/ros.h"
#include "ex3_demo_services/demo_srv.h"
#include <iostream>
#include <sstream>


//Defining namespace using in this code
using namespace std;
//using namespace ros;
//using namespace std_msgs;
//using namespace ex3_demo_services;


bool demo_service_callback(ex3_demo_services::demo_srv::Request  &req,
         ex3_demo_services::demo_srv::Response &res)
{
  std::stringstream ss;
  ss << "Received  Here";
  res.out = ss.str();

  ROS_INFO("From Client  [%s], Server says [%s]",req.in.c_str(),res.out.c_str());

  return true;


}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "demo_service_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("demo_service", demo_service_callback);
  ROS_INFO("Ready to receive from client.");
  ros::spin();

  return 0;
}