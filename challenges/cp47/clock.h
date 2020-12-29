#pragma once

class Clock
{
private:
    const unsigned int mins;
    const unsigned int hours;

    float get_mins_angle() const;
    float get_hours_angle() const;

public:
    Clock(unsigned int mins, unsigned int hours) : mins(mins), hours(hours){};

    bool is_valid() const;
    float get_angle() const;
};
