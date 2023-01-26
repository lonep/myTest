#include "helix.h"

using namespace Curves;

Helix::Helix(double r, double step, double x, double y, double z)
    :
      Curve(x, y, z), r{r}, step{step}
{
    coordinates.x = x;
    coordinates.y = y;
}

Point3D Helix::get3Dpoint(double t)
{
    double X = t * r * cos(t) + coordinates.x;
    double Y = t * r * sin(t) + coordinates.y;
    double Z = step * t;

    return Point3D(X, Y, Z);
}

Point3D Helix::get3Dvector(double t)
{
    return Point3D(-r*sin(t), r*cos(t), step);
}
