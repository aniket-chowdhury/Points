#include <boost/numeric/ublas/fwd.hpp>
#include <iostream>
#include <fstream>
#include <memory>
#include "points.hpp"

int main()
{
	geometry::Point<int> p(4, 3);
	geometry::Point<int> q(2, 3);
	geometry::Point<int> r(4, 3);
	std::cout << geometry::distance(p, q);
}