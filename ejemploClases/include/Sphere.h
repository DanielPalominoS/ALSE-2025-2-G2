#ifndef __SPHERE_H__
#define __SPHERE_H__

/**
 * @file Sphere.h
 * @brief Declaration of the Sphere concrete 3D shape.
 *
 * The Sphere class implements the Shape3D interface and provides
 * methods to compute the volume and surface area of a sphere. The
 * class stores the sphere size in the private member `radious` (the
 * radius of the sphere).
 */

#include "Shape3d.h"
#include <iostream>
#include <cmath>

/**
 * @class Sphere
 * @brief Concrete implementation of a three-dimensional sphere.
 *
 * Sphere represents a geometric sphere defined by its radius. It
 * implements the Shape3D interface by providing concrete
 * implementations for computing volume and surface area.
 */
class Sphere : public Shape3D {
private:
    /**
     * @brief Radius of the sphere.
     *
     * Note: the member name uses the spelling `radious` to match the
     * original codebase. It stores the radius in the same units used
     * across the project (typically double precision floating point).
     */
    double radious;
public:
    /**
     * @brief Construct a Sphere with a specified radius.
     *
     * If the provided radius is not positive, the implementation
     * will typically fall back to a default positive radius (see
     * implementation in Sphere.cpp).
     *
     * @param len Radius of the sphere (must be > 0 to be accepted).
     */
    Sphere(double len);

    /**
     * @brief Default constructor.
     *
     * Constructs a sphere with a default radius (usually 1.0).
     */
    Sphere();

    /**
     * @brief Compute the volume of the sphere.
     *
     * Implements Shape3D::getVolume(). Returns the volume using the
     * formula: (4/3) * pi * r^3.
     *
     * @return Volume as a double.
     */
    double getVolume() const override;

    /**
     * @brief Compute the surface area of the sphere.
     *
     * Implements Shape3D::getSurfaceArea(). Returns the surface area
     * using the formula: 4 * pi * r^2.
     *
     * @return Surface area as a double.
     */
    double getSurfaceArea() const override;

    /**
     * @brief Set the sphere radius.
     *
     * Sets the radius to the provided value if it is positive. If the
     * value is non-positive, the radius is left unchanged.
     *
     * @param len New radius value (must be > 0 to take effect).
     */
    void setLength(double len);

    /**
     * @brief Get the sphere radius.
     *
     * Returns the current radius stored in the object.
     *
     * @return Radius as a double.
     */
    double getLength() const;

    /**
     * @brief Virtual destructor.
     *
     * Ensures proper cleanup of resources. Marked override to match
     * the Shape3D virtual destructor.
     */
    ~Sphere() override;
};

#endif // __SPHERE_H__