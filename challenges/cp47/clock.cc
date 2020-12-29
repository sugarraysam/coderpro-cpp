#include "clock.h"
#include <cmath>

/*
Angles of a Clock - https://leetcode.com/problems/angle-between-hands-of-a-clock/

Given two integers, an hour and a minute, write a function to calculate
the angle between the two hands on a clock representing that time.

Time-Complexity:
    O(1), we make a fixed number of computations

Space-Complexity:
    O(1), we store two integers for mins and hours
*/

bool Clock::is_valid() const
{
    // hours in [1, 12], mins in [0, 60)
    return mins < 60 && (hours >= 1 && hours <= 12);
}

float Clock::get_angle() const
{
    float angle = std::abs(this->get_mins_angle() - this->get_hours_angle());
    return std::fmin(angle, 360.0f - angle);
}

float Clock::get_mins_angle() const
{
    return (360.0f / 60.0f) * mins;
}

float Clock::get_hours_angle() const
{
    return (360.0f / (60.0f * 12.0f)) * (hours * 60 + mins);
}
