#ifndef __CUBE_H__
#define __CUBE_H__
#include "Shape3d.h"
#include <iostream>
class Cube : public Shape3D {
private:
    double length;
public:
    Cube(double len);
    Cube();
    double getVolume() const override;
    double getSurfaceArea() const override;
    void setLength(double len);
    double getLength() const;
    ~Cube() override;
};
#endif // __CUBE_H__