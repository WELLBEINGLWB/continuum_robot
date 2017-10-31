/*
 * simulator.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: haitham
 */
#include <iostream>
#include "continuum_robot/Continuum.h"


int main( int argc, char** argv )
{
  ros::init(argc, argv, "continuum_core");
  Continuum robot(3); // create an object robot with three sections

 // set the base Pose
 robot.setSegmentBasePose(0,tf::Vector3(0,0,0),tf::createQuaternionFromRPY(0.0, 90*PI/180,0.0));

// Assign the parameters for each section
 robot.addSegment(0,5,30,.3); // SegID , Length, noOfSegments, radius of disk
 robot.setSegmentShape(0,0.0001,0); // SegID , Kappa, Phi



robot.addSegment(1,10,30,.3); // SegID , Length, noOfSegments
robot.setSegmentShape(1,0.0001,0); // SegID , Kappa, Phi



 robot.addSegment(2,6,6,.2); // SegID , Length, noOfSegments
 robot.setSegmentShape(2,0.0001,0); // SegID , Kappa, Phi

// Moving demonstration:
  while (ros::ok())
  { // set a pattern
for(double i=0.25;i>=-0.25;i=i-0.01)
{
robot.setSegmentShape(0,i,0); // SegID , Kappa, Phi
robot.update();
}

for(double i=0.1;i<=.5;i=i+0.01)
{
	robot.setSegmentShape(1,i,PI/2); // SegID , Kappa, Phi
robot.update();
}

for(double i=.5;i>=0.1;i=i-0.01)
{
	robot.setSegmentShape(1,i,PI/2); // SegID , Kappa, Phi
robot.update();
}

for(double i=-.5;i<=.5;i=i+0.01)
{
	robot.setSegmentShape(2,i,PI/7); // SegID , Kappa, Phi
robot.update();
}

for(double i=.5;i>=-.5;i=i-0.01)
{
	robot.setSegmentShape(2,i,PI/7); // SegID , Kappa, Phi
robot.update();
}
   }
}
