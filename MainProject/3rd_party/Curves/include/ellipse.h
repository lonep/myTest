#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"

namespace Curves
{
    class CURVES_EXPORT Ellipse : public Curve
    {
    public:
        Ellipse();
        Ellipse(double a, double b, double x = 0, double y = 0);

        virtual Point3D get3Dpoint(double t) override;
        virtual Point3D get3Dvector(double t) override;

    private:
        //Радиусы эллипса
        double a;
        double b;
    };
}


#endif // ELLIPSE_H
