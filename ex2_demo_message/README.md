* We are going to create a message file called demo_msg.msg with the following definition:

  string greeting
  
  int32 number

* Until now, we have worked only with standard message definitions. Now, we have created our own definitions and can see how to use them in our code.
The first step is to edit the package.xml file of the current package and uncomment
the lines <build_depend>message_generation</build_depend> and <run_depend>message_runtime</run_depend> .

* Edit the current CMakeLists.txt and add the message_generation line as follows:

  find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    std_msgs
    actionlib
    actionlib_msgs
    message_generation
  )

* Uncomment the following line and add the custom message file:

  add_message_files(

  FILES

  demo_msg.msg

  )
  
##Generate added messages and services with any dependencies listed here

  generate_messages(

    DEPENDENCIES

    std_msgs

    actionlib_msgs

  )
* After these steps, we can compile and build the package:

  $ cd ~/catkin_ws/

  $ catkin_make
