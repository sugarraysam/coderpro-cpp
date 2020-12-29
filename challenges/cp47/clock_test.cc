#include "clock.h"
#include "gtest/gtest.h"

struct Case
{
    int hours;
    int mins;
    bool is_valid;
    float angle;
};

std::vector<Case> TestCases = {
    Case{12, 30, true, 165.0},
    Case{3, 30, true, 75.0},
    Case{3, 15, true, 7.5},
    Case{4, 50, true, 155.0},
    Case{12, 0, true, 0.0},
    Case{0, 50, false, -1.0},
    Case{4, 60, false, -1.0},
    Case{4, -2, false, -1.0},
    Case{15, 50, false, -1.0},
};

TEST(CP47, TestClockIsValid)
{
    for (auto &tc : TestCases)
    {
        Clock c = Clock(tc.mins, tc.hours);
        ASSERT_EQ(c.is_valid(), tc.is_valid);
    }
}

TEST(CP47, TestAngleBetweenHands)
{
    for (auto &tc : TestCases)
    {
        Clock c = Clock(tc.mins, tc.hours);
        if (c.is_valid())
        {

            ASSERT_EQ(c.get_angle(), tc.angle);
        }
    }
}
