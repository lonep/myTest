#ifndef CIRCLE_H
#define CIRCLE_H

#include "curve.h"
#include "Curves_global.h"

namespace Curves {
    class CURVES_EXPORT Circle : public Curve
    {
    public:
        Circle();
        Circle(double r = 0, double x = 0, double y = 0);

        virtual Point3D get3Dpoint(double t) override;
        virtual Point3D get3Dvector(double t) override;

        virtual double radius() override;

    private:
        double r;
    };
}


#endif // CIRCLE_H
