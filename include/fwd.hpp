namespace geometry
{
/*Defines a 2d point in cartesian system
in the geometry namespace. */
template <typename T>
struct Point;

/*Find distance between two points in cartesian plane. */
template <typename T>
auto distance();

/* Return 0 if all are co-linear,
1 for clockwise,
2for anti-clockwise*/
template <typename T, typename U, typename V>
int orientation();

//Checks if three points are co-linear
template <typename T, typename U, typename V>
bool is_colinear();

//Checks if three points are clockwise
template <typename T, typename U, typename V>
bool is_clockwise();

//Checks if three points are anti-clockwise
template <typename T, typename U, typename V>
bool is_anti_clockwise();
} // namespace geometry