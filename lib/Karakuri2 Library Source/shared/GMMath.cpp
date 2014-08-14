//
//  GMMath.cpp
//  Game Framework
//
//  Created by numata on Jan 02, 2011.
//  Copyright 2010-2012 Sazameki and Satoshi Numata, Ph.D. All rights reserved.
//

#include "GMMath.h"

#include <algorithm>
#include <cmath>


const double GMMath::kDoubleEqThreshold   = 0.00000001;
const float GMMath::kFloatEqThreshold    = 0.00000001f;


double GMMath::Barycentric(double v1, double v2, double v3, double t1, double t2)
{
    return ((1.0 - t1 - t2) * v1) + (t1 * v2) + (t2 * v3);
}

double GMMath::CatmullRom(double v1, double v2, double v3, double v4, double t)
{
    double t2 = t * t;
    double t3 = t2 * t;
    
    double temp1 = (v3 - v1) / 2;
    double temp2 = (v4 - v2) / 2;
    
    return (2 * v2 - 2 * v3 + temp1 + temp2) * t3 + (-3 * v2 + 3 * v3 - 2 * temp1 - temp2) * t2 + temp1 * t + v2;    
}

double GMMath::Clamp(double x, double minVal, double maxVal)
{
    return std::min(std::max(x, minVal), maxVal);
}

double GMMath::Distance(double value1, double value2)
{
    return fabs(value2 - value1);
}

double GMMath::EaseIn(double value1, double value2, double t)
{
    return value1 + (value2 - value1) * (t * t);
}

double GMMath::EaseInOut(double value1, double value2, double t)
{
    double middle = (value1 + value2) / 2;
    t *= 2;
    if (t <= 1.0) {
        return (value1 + (middle - value1) * (t * t));
    }
    t -= 1;
    return middle - (value2 - middle) * (t * (t - 2));
}

double GMMath::EaseOut(double value1, double value2, double t)
{
    return value1 - (value2 - value1) * (t * (t - 2));
}

double GMMath::Hermite(double value1, double tan1, double value2, double tan2, double t)
{
    double t3 = t * t * t;
    double t2 = t * t;
    
    double h1 = 2.0 * t3 - 3.0 * t2 + 1.0;
    double h2 = -2.0 * t3 + 3.0 * t2;
    double h3 = t3 - 2.0 * t2 + t;
    double h4 = t3 - t2;
    
    return h1 * value1 + h2 * value2 + h3 * tan1 + h4 * tan2;    
}

double GMMath::Lerp(double value1, double value2, double t)
{
    return value1 + (value2 - value1) * t;
}

double GMMath::Max(double value1, double value2)
{
    return (value1 >= value2)? value1: value2;
}

double GMMath::Min(double value1, double value2)
{
    return (value1 <= value2)? value1: value2;
}

double GMMath::SmoothStep(double edge0, double edge1, double x)
{
    double t = Clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
    return t * t * (3.0 - 2.0 * t);
}

double GMMath::ToDegrees(double radians)
{
    return radians * 180.0 / M_PI;
}

double GMMath::ToRadians(double degrees)
{
    return degrees * M_PI / 180.0;
}

double GMMath::WrapAngle(double radians)
{
    if (radians < -M_PI) {
        while (radians < -M_PI) {
            radians += 2 * M_PI;
        }
    } else if (radians > M_PI) {
        while (radians > M_PI) {
            radians -= 2 * M_PI;
        }
    }
    return radians;
}


