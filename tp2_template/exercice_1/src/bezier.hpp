#pragma once

#ifndef BEZIER_HPP
#define BEZIER_HPP

#include <iostream>
#include <math.h>  

struct bezier
{
    public:
        bezier();
        bezier(float p0_arg, float p1_arg,float p2_arg,float p3_arg);
        float coeff(int index)const;
        float& coeff(int index);
        float operator()(float s)const;

    private:

        float P[4];
};

//Should print on the command line
// (1-s)^3*p0+3s(1-s)^2*p1+3s^2(1-s)*p2+s^3*p3
std::ostream& operator<<(std::ostream& stream,bezier const& b);


#endif