#include "curve.h"

using namespace Curves;

Curve::~Curve()
{
    //Delete something
}

Curve::Curve( int x, int y, int z)
{
    coordinates.x = x;
    coordinates.y = y;
    coordinates.z = z;
}

double Curve::radius()
{
    return 0;
}
