//This code is the ROS service server code which will receive the integer from service client

#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

#include "ex3_demo_services/demo_srv.h"
#include <sstream>


//Defining namespace using in this code
using namespace std;
//using namespace ros;
//using namespace std_msgs;
//using namespace ex3_demo_services;


int main(int argc, char **argv)
{
  ros::init(argc, argv, "demo_service_client");


  ros::NodeHandle n;
  ros::Rate loop_rate(10);

  ros::ServiceClient client = n.serviceClient<ex3_demo_services::demo_srv>("demo_service");

	while (ros::ok())
	{


	  ex3_demo_services::demo_srv srv;
	  std::stringstream ss;
	  ss << "Sending from Here";
	  srv.request.in = ss.str();


	  if (client.call(srv))
	  {

	    ROS_INFO("From Client  [%s], Server says [%s]",srv.request.in.c_str(),srv.response.out.c_str());

	  }
	  else
	  {
	    ROS_ERROR("Failed to call service");
	    return 1;
	  }

	ros::spinOnce();
	//Setting the loop rate
	loop_rate.sleep();

	}
  return 0;
}
