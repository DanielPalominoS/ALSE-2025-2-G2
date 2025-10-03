#ifndef __SPHERE_H__
#define __SPHERE_H__
#include "Shape3d.h"
#include <iostream>
#include <cmath>
class Sphere : public Shape3D {
private:
    double radious;
public:
    Sphere(double len);
    Sphere();
    double getVolume() const override;
    double getSurfaceArea() const override;
    void setLength(double len);
    double getLength() const;
    ~Sphere() override;
};
#endif // __CUBE_H__