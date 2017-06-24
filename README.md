# Region Tree

A datatype suitable for rectangular binary space partitioning (BSP) on a 2-dimensional plane (X,Y).

## Usage

```c++
// Define a region with top-left and bottom-right coordinates
Point top_left = Point(10, 30);
Point bottom_right = Point(40, 0);

Region region = Region(top_left.x, top_left.y, bottom_right.x, bottom_right.y);

// Split the region vertically along x=20
region.split_vertically(20);

// Calculate region dimensions
int area = region.area();
int width = region.width();
int height = region.height();

// Define a point to sample the region
Point a = Point(1,1);

// Test a point inside the region
bool point_in_region = region.point_in_region(a);
bool point_in_border = region.point_in_border(a);

// Check if region has children and retrieve them
if (region.has_chilren()) {
    Region *left_child = region.get_child(LEFT);
    Region *right_child = region.get_child(RIGHT);
}

// Destroy a region along with its children
delete region;
```

## Compiling

Just run `make` to compile the project and `make clean` to delete the test application and object files once you're done :)
