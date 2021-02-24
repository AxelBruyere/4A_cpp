#include "bezier.hpp"

#include <cstdlib>
#include <math.h>

bezier::bezier()
{
    P[0]=(0.0f);
    P[1]=(0.0f);
    P[2]=(0.0f);
    P[3]=(0.0f);
}

bezier::bezier(float p0_arg, float p1_arg,float p2_arg,float p3_arg)
{
    P[0]=p0_arg;
    P[1]=p1_arg;
    P[2]=p2_arg;
    P[3]=p3_arg;
}

float bezier::coeff(int index)const
{
    return P[index];
}

float& bezier::coeff(int index)
{
    return P[index];
}

std::ostream& operator<<(std::ostream& stream,bezier const& b)
{
    stream<<"(1-s)^3*"<<b.coeff(0)<<"+(1-s)^2*s*"<<b.coeff(1)<<"+(1-s)*s^2*"<<b.coeff(2)<<"+s^3*"<<b.coeff(3);
    return stream;
}

float bezier::operator()(float s) const
{
    float value = pow(1-s,3)*P[0]+3*s*pow(1-s,2)*P[1]+3*pow(s,2)*(1-s)*P[2]+pow(s,3)*P[3];
    return value;
}