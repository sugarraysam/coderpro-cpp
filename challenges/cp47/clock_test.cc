#include "clock.h"
#include "gtest/gtest.h"

struct Case
{
    unsigned int hours;
    unsigned int mins;
    bool is_valid;
    float angle;
};

std::vector<Case> TestCases = {
    Case{hours : 12, mins : 30, is_valid : true, angle : 165.0f},
    Case{hours : 3, mins : 30, is_valid : true, angle : 75.0f},
    Case{hours : 3, mins : 15, is_valid : true, angle : 7.5f},
    Case{hours : 4, mins : 50, is_valid : true, angle : 155.0f},
    Case{hours : 12, mins : 0, is_valid : true, angle : 0.0f},
    Case{hours : 0, mins : 50, is_valid : false, angle : -1.0f},
    Case{hours : 4, mins : 60, is_valid : false, angle : -1.0f},
    Case{hours : 4, mins : 999, is_valid : false, angle : -1.0f},
    Case{hours : 15, mins : 50, is_valid : false, angle : -1.0f},
};

TEST(CP47, TestClockIsValid)
{
    for (auto &tc : TestCases)
    {
        Clock c(tc.mins, tc.hours);
        ASSERT_EQ(c.is_valid(), tc.is_valid);
    }
}

TEST(CP47, TestAngleBetweenHands)
{
    for (auto &tc : TestCases)
    {
        Clock c(tc.mins, tc.hours);
        if (c.is_valid())
        {
            ASSERT_EQ(c.get_angle(), tc.angle);
        }
    }
}
