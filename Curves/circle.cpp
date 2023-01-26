#include "circle.h"
using namespace Curves;

Circle::Circle()
{

}

Circle::Circle(double r, double x, double y)
    : Curve(x, y, 0), r{r}
{

}

Point3D Circle::get3Dpoint(double t)
{
    double X = r * cos(t) + coordinates.x;
    double Y = r * sin(t) + coordinates.y;

    return Point3D(X, Y, 0);
}

Point3D Circle::get3Dvector(double t)
{
    return Point3D(cos(t)/-sin(t), 1, 0);
}

double Circle::radius()
{
    return r;
}


