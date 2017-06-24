#include <iostream>
#include "region.h"

void print_region(Region &region) {
    std::cout << "Region has dimensions W,H (" << region.width() << ", " << region.height() << "). Area = " << region.area() << std::endl;
    if (region.has_children()) {
        print_region(*region.get_child(FIRST));
        print_region(*region.get_child(SECOND));
    }
}

int main(int argc, char *argv[]) {

    Point a = Point(1,1);
    Point b = Point(2,2);

    Region root = Region(0,0,10,10);

    float distance = a.distance_to(b);

    std::cout << "Distance is = " << distance << std::endl;
    std::cout << "Root region has width " << root.width() << " and height " << root.height() << " with area " << root.area() << std::endl;

    // Split the region!
    root.split_horizontally(5);

    print_region(root);
    return 0;
}
