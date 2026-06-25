#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include "point.h"
#include <string>

struct Circle {
    Point center;
    double radius;
};

double distance(const Circle * c,const Point * p){
    return std::pow(p->x - c->center.x,2) + pow(p->y - c->center.y,2);
}
std::string CheckPointInCircle(double distance, int r2){
    if(distance < r2){
        return "Inside";
    }
    else if(distance == r2){
        return "On Circle";
    }
    else{
        return"Outside";
    }
}

#endif