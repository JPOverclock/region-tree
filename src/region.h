#ifndef __REGION_H__
#define __REGION_H__

#include "point.h"

#define TOP 0
#define LEFT 0
#define FIRST 0
#define BOTTOM 1
#define RIGHT 1
#define SECOND 1

class Region {
public:
    Region(int a, int b, int c, int d) : top_left(Point(a,b)), bottom_right(Point(c,d)) {
        parent = 0;
        children[FIRST] = 0;
        children[SECOND] = 0;
    }

    ~Region() {
        for (int i = FIRST; i <= SECOND; i++) {
            if (children[i]) { delete children[i]; }
        }
    }

    int width() { return bottom_right.x - top_left.x; }
    int height() { return bottom_right.y - top_left.y; }

    int area() { return width() * height(); }

    void split_vertically(int x);
    void split_horizontally(int y);

    bool point_in_region(Point point);
    bool point_in_border(Point point);

    bool has_children() { return children[FIRST] || children[SECOND]; }
    Region *get_child(int position) { return children[position]; }
private:
    Point top_left;
    Point bottom_right;

    Region *parent;
    Region *children[2];
};

#endif //__REGION_H__
