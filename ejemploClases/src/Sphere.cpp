#include "Sphere.h"
Sphere::Sphere(double len)
{
    if (len > 0)
    {
        radious = len;
    }
    else
    {
        radious = 1.0; // Default radious if invalid
    }
}
Sphere::Sphere()
{
    radious = 1.0;
}
double Sphere::getVolume() const
{
    //return (4.0/3.0) * M_PI * pow(radious, 3);
    return (4.0/3.0) * 3.14159265358979323846 * radious * radious * radious;
}
double Sphere::getSurfaceArea() const{
    return 4 * 3.14159265358979323846 * radious * radious;
}
void Sphere::setLength(double len){
    if (len > 0)
    {
        radious = len;
    }
}
double Sphere::getLength() const{
    return radious;
}
Sphere::~Sphere() {
    // Destructor logic if needed
    std::cout<<"Sphere destructor called"<<std::endl;
}