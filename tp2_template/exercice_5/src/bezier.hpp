#pragma once

#ifndef BEZIER_HPP
#define BEZIER_HPP

#include <iostream>
#include <math.h>  
#include <limits>

template <typename T>
struct geometrical_object
{
    public:
    virtual T closest_point(T P0) const;
};


template <typename T>
struct bezier //: public geometrical_object
{
    private:

        T P[4];


    public:
        
        bezier()
        {
            P[0]= T();
            P[1]= T();
            P[2]= T();
            P[3]= T();
        };

        bezier(T p0_arg, T p1_arg,T p2_arg,T p3_arg)
        {
            P[0]=p0_arg;
            P[1]=p1_arg;
            P[2]=p2_arg;
            P[3]=p3_arg;
        }

        T coeff(int index)const
        {
            return P[index];
        }

        T& coeff(int index)
        {
            return P[index];
        }

        T operator()(float s) const
        {
            T value = pow(1-s,3)*P[0]+3*s*pow(1-s,2)*P[1]+3*pow(s,2)*(1-s)*P[2]+pow(s,3)*P[3];
            return value;
        }

        T closest_point(T P0) const
        {
            int N = 10;
            float s = 0.0f;
            float dist_i = 0.0f;
            float dist_min = std::numeric_limits<T>::infinity();
            T P_i();
            T P_proche();
            for (int i=0; i<N+1; i++)
            {
                P_i = pow(1-s,3)*P[0]+3*s*pow(1-s,2)*P[1]+3*pow(s,2)*(1-s)*P[2]+pow(s,3)*P[3];
                dist_i = norm(P0-P_i);
                if (dist_i<dist_min)
                {
                    dist_min = dist_i;
                    P_proche = P_i;
                }
                s = s + 1/N;
            }
            return P_proche;
        }
        
    };
    
template <typename T>
struct circle //: public geometrical_object
{
    private:
        T C[2];
        float r;

    public:
        circle()
        {
            C = T();
            r = 0.0f;
        }

        circle(T C_arg, float r_arg)
        {
            C = C_arg;
            r = r_arg;
        }
       

        T closest_point(T P0) const
        {
            T P_i;
            P_i = C + (r/norm(P0-C)) * (P0-C);
            return P_i;
        }

};


    
    //Should print on the command line
    // (1-s)^3*p0+3s(1-s)^2*p1+3s^2(1-s)*p2+s^3*p3
    template <typename S>
    std::ostream& operator<<(std::ostream& stream,bezier<S> const& b)
    {
        stream<<"(1-s)^3*"<<b.coeff(0)<<"+(1-s)^2*s*"<<b.coeff(1)<<"+(1-s)*s^2*"<<b.coeff(2)<<"+s^3*"<<b.coeff(3);
        return stream;
    }   ;
    
#endif