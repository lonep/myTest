#ifndef HELIX_H
#define HELIX_H

#include "curve.h"

namespace Curves {
    class CURVES_EXPORT Helix : public Curve
    {
    public:

        Helix(double r, double step, double x = 0, double y = 0, double z = 0);
        virtual Point3D get3Dpoint(double t) override;
        virtual Point3D get3Dvector(double t) override;

    private:
        double r;
        double step;
    };
}

#endif // HELIX_H
