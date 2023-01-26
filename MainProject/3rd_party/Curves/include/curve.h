#ifndef CURVE_H
#define CURVE_H

#define PI 3.14
#include <cmath>

#include "Curves_global.h"

namespace Curves
{
    struct Point3D
    {
        Point3D(double x = 0, double y = 0, double z = 0)
            : x{x}, y{y}, z{z}
        {}

        double x;
        double y;
        double z;
    };

    class CURVES_EXPORT Curve
    {
    public:

        ~Curve();

        Curve(int x = 0, int y = 0, int z = 0);

        virtual Point3D get3Dpoint(double t) = 0;
        virtual Point3D get3Dvector(double t) = 0;

        virtual double radius();

    protected:
        Point3D coordinates;
    };

}

#endif // CURVE_H
