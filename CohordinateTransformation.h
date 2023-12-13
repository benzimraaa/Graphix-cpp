#include "Graphix.h"

class CohordinateTransformation
{
private:
    Graphix* gfx;
public:
    CohordinateTransformation(Graphix* gfx);
    ~CohordinateTransformation();
};

CohordinateTransformation::CohordinateTransformation(Graphix* gfx)
{
    this->gfx = gfx;
}

CohordinateTransformation::~CohordinateTransformation()
{
}
