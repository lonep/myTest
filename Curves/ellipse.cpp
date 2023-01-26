#include "ellipse.h"

using namespace Curves;

Ellipse::Ellipse()
{

}

Ellipse::Ellipse(double a, double b, double x, double y)
    : Curve(x, y, 0), a{a}, b{b}
{
}

Point3D Ellipse::get3Dpoint(double t)
{
        double X = a * cos(t) + coordinates.x;
        double Y = b * sin(t) + coordinates.y;

        return Point3D(X, Y, 0);
}

Point3D Ellipse::get3Dvector(double t)
{
    return Point3D(b*cos(t)/(-a*sin(t)), 1, 0);
}
