#include <utility>
#include <iostream>
#include <cmath>
#include <concepts>
#include "fwd.hpp"
#include <concepts>

namespace geometry
{   
template <class T>
concept integral = std::is_integral<T>::value;

template <typename T = int>
struct Point
{
    /*X co-ordinate*/
    T X() { return p.first; }

    /*Y co-ordinate*/
    T Y() { return p.second; }

    /*Baseline Constructor*/
    Point(T x, T y) requires integral<T>
    {
        this->operator()(x, y);
    }

    /*Return a Point with new variables.*/
    Point operator()(T x, T y)
    {
        p = std::make_pair(x, y);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const Point &point)
    {
        out << "(" << point.p.first << "," << point.p.second << ")";
        return out;
    }

    /*Find distance between two points in cartesian plane. */
    auto distance(Point &p = Origin)
    {
        return std::sqrt(std::pow(X() - p.X(), 2) + std::pow(Y() - p.Y(), 2));
    }

    static Point<int> Origin;

private:
    std::pair<T, T> p;
    T x, y;
};

template <class T>
Point<int> Point<T>::Origin = Point<int>(0, 0);

Point<int> Origin = Point<int>::Origin;

/*Find distance between two points in cartesian plane. */
template <typename T>
auto distance(Point<T> &p1, Point<T> &p2 = Origin)
{
    return p1.distance(p2);
}

/* Return 0 if all are co-linear,
1 for clockwise,
2for anti-clockwise*/
template <typename T, typename U, typename V>
int orientation(Point<T> p, Point<U> q, Point<V> r)
{
    int val = (q.Y() - p.Y()) * (r.X() - q.X()) - (q.X() - p.X()) * (r.Y() - q.Y());
    return val == 0 ? 0 : (val > 0 ? 1 : 2);
}

// Checks if three points are co-linear
template <typename T, typename U, typename V>
bool is_colinear(Point<T> p, Point<U> q, Point<V> r)
{
    return orientation(p, q, r) == 0;
};

//Checks if three points are clockwise
template <typename T, typename U, typename V>
bool is_clockwise(Point<T> p, Point<U> q, Point<V> r)
{
    return orientation(p, q, r) == 1;
};

//Checks if three points are anti-clockwise
template <typename T, typename U, typename V>
bool is_anti_clockwise(Point<T> p, Point<U> q, Point<V> r)
{
    return !is_clockwise(p, q, r);
};
} // namespace geometry