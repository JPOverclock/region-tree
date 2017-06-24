#ifndef __POINT_H__
#define __POINT_H__

#include <cmath>

class Point {
public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}

    float distance_to(Point &point) {
        int x_difference = x - point.x;
        int y_difference = y - point.y;

        return sqrt((x_difference * x_difference) + (y_difference * y_difference));
    }
};

#endif //__POINT_H__
