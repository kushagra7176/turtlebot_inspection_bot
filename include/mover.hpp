/**
 *
 * Copyright (c) 2020 Kartik Venkat Kushagra Agrawal Aditya Khopkar
 *
 * @section LICENSE
 *
 * MIT License
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file mover.hpp
 *
 * @authors
 * Kartik Venkat kartik.venkat86@gmail.com \n
 * Kushagra Agrawal kushagraagrawal425@gmail.com  \n
 * Aditya Khopkar aadi0110@gmail.com  \n
 *
 * @version 1.0
 *
 * @section DESCRIPTION:
 * This is the class declaration for the Turtlebot Mover node.
 */

#ifndef INCLUDE_MOVER_HPP_
#define INCLUDE_MOVER_HPP_

#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose2D.h>
#include <iostream>
#include <string>
/*
 * @brief Mover class for TurtleBot
 *
 */

class TurtlebotMover {
 private:
    geometry_msgs::Twist velMsg;
    ros::NodeHandle nh;
    ros::Publisher pubVel;
    ros::Subscriber getVel;
    ros::Subscriber subLaserScanner;
    ros::Subscriber sub_odometry;
    geometry_msgs::Pose2D current_pose;
    bool isGoal;
    bool isObstacle;
    double obstacleThresh;
    std::string newDirection;


 public:
    /*
     * @brief Constructor for turtlebotMover class.
     */
    TurtlebotMover();

    float linX, angZ;
    /*
     * @ brief Callback service to get the current velocity of the turtlebot
     * from the environment.
     * @ param vel: Pointer for velocity from the Twist sensor.
     * @ return none.
     */
    void velocityCallback(const geometry_msgs::Twist::ConstPtr& vel);
    /*
     *  @brief Callback service to get the current pose of the turtlebot
     *  from the environment
     *  @param msg: Pointer to messages from Odometry sensor.
     *  @return none.
     */
    void odomCallback(const nav_msgs::Odometry::ConstPtr& msg);
    /*
     * @brief Callback service to scan the environment for obstacles.
     * @param msg : Pointer for messages from the LaserScan sensor.
     * @return none.
     */
    void scanEnvCallback(const sensor_msgs::LaserScan::ConstPtr& msg);

    /*
     * @brief Check if an obstacle is present in the Turtlebot's path.
     * @param none.
     * @return bool value determining if obstacle is detected.
     */
    bool checkObstacle();
    /*
     * @brief Check if the turtlebot has reached the goal.
     * @param current_pose: type Pose2D (stores current pose
     * of the turtlebot.)
     * @return bool value determining whether goal is reached or not.
     */
    bool isGoalReached(geometry_msgs::Pose2D current_pose);

    /*
     * @brief Sets the isObstacle flag indicating that there is an
     * obstacle ahead.
     * @param obstacle: bool value
     * @return none.
     */
    void setObstacle(bool obstacle);

    /*
     * @brief Function that turns the TurtleBot according to the direction specified.
     * @param newDirection: std::string that indicates the new direction.
     * @return none.
     */
    double changeDirection(const std::string &newDirection);

    /*
     * @brief Function that moves the TurtleBot in the environment.
     * @param TEST = false.
     * @return none.
     */
    void moveRobot(bool TEST = false);

    /*
     * @brief Destructor for the TurtlebotMover class
     */
    ~TurtlebotMover();
};


#endif  // INCLUDE_MOVER_HPP_
