#include "region.h"

bool Region::point_in_region(Point point) {
    return (point.x >= top_left.x) &&
        (point.x <= bottom_right.x) &&
        (point.y >= top_left.y) &&
        (point.y <= bottom_right.y);
}

bool Region::point_in_border(Point point) {
    return (((point.x == top_left.x) || (point.x == bottom_right.x)) &&
            ((point.y <= bottom_right.y) && (point.y >= top_left.y))) ||
        (((point.y == top_left.y) || (point.y == bottom_right.y)) &&
         ((point.x >= top_left.x) && (point.x <= bottom_right.x)));
}

void Region::split_vertically(int x) {
    if (!point_in_region(Point(x, top_left.y))) return;

    Region *left = new Region(top_left.x, top_left.y, bottom_right.x + x, bottom_right.y);
    Region *right = new Region(top_left.x + x, top_left.y, bottom_right.x, bottom_right.y);

    children[LEFT] = left;
    children[RIGHT] = right;
}

void Region::split_horizontally(int y) {
    if (!point_in_region(Point(top_left.x, y))) return;

    Region *top = new Region(top_left.x, top_left.y, bottom_right.x, bottom_right.y - y);
    Region *bottom = new Region(top_left.x, top_left.y + y, bottom_right.x, bottom_right.y);

    children[TOP] = top;
    children[BOTTOM] = bottom;
}
