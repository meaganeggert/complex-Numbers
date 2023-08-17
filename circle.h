#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h"

class Circle {
        //YOU: Make some member variables to describe a circle
        private:
        Point center;
        float radius;

        public:
        Circle () { exit(1); }
        Circle (float newCentX, float newCentY, float newRad) : center({newCentX, newCentY}), radius(newRad) {
                //if (newRad <= 0) die();
        }

        float get_X() const { return center.x; }
        float get_Y() const { return center.y; }
        float get_Rad() const { return radius; }
        void set_X(float newX) { center.x = newX; }
        void set_y(float newY) { center.y = newY; }
        void set_Rad(float newR) {
                //if (newR <= 0) die();
                radius = newR;
        }

        bool isIn ( const Point &testPoint ) const {
                float distance = hypot(center.x - testPoint.x, center.y - testPoint.y);
                if (distance - radius < 0 ) return true;
                return false;
        }

        //Maybe make an operator>> and operator<<

        friend std::istream& operator>>(std::istream& ins, Circle &inputCircle) {
        return ins >> inputCircle.center.x >> inputCircle.center.y >> inputCircle.radius;
        }

    friend std::ostream& operator<<(std::ostream& outs, const Circle &outputCircle) {
        return outs << '(' << outputCircle.center.x << ',' << outputCircle.center.y << ") with radius " << outputCircle.radius;
        }


        //Make a distance_to function that returns how far away a given point is from the edge of the circle

    float distance_to ( const int &curJ, const int &curI ) const {
        float distance;
        distance = hypot(curJ - center.x, curI - center.y);
        distance = distance - radius;
        distance = trunc(distance);
        return distance;
    }



};
#endif
