#pragma once

class Clock
{
private:
    const int mins;
    const int hours;

    float get_mins_angle() const;
    float get_hours_angle() const;

public:
    Clock(int mins, int hours) : mins(mins), hours(hours){};
    bool is_valid() const;
    float get_angle() const;
};
