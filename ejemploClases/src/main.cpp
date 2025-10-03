#include "Complex.h"
#include <iostream>
#include "Sphere.h"
#include "Cube.h"
int main() {
    Complex c1(3, 4), c2(1, 2);
    cout << "c1: " << c1.GetReal()<<"+"<<c1.GetImag()<<"i" << endl;
    cout<<"c1"<<c1<<endl;
    //c1.real = 5; // Direct access to public member
    c1.SetReal(5);
    c1.display();
    c2.display();
    c2.GetImag();
    c2.SetImag(5.2);
    Complex sum = c1 + c2;
    sum.display();
    cout<<"c2.real: "<<c2.GetReal()<<  endl;
    Cube cube(3.0);
    Sphere sphere(2.0);
    std::cout << "Cube Volume: " << cube.getVolume() << std::endl;
    std::cout << "Cube Surface Area: " << cube.getSurfaceArea() << std::endl;
    std::cout << "Sphere Volume: " << sphere.getVolume() << std::endl;
    std::cout << "Sphere Surface Area: " << sphere.getSurfaceArea() << std::endl;
    Cube* cubePtr = new Cube(4.0);
    Sphere* spherePtr = new Sphere(3.0);
    std::cout << "Cube Pointer Volume: " << cubePtr->getVolume() << std::endl;
    std::cout << "Cube Pointer Surface Area: " << cubePtr->getSurfaceArea() << std::endl;
    std::cout << "Sphere Pointer Volume: " << spherePtr->getVolume() << std::endl;
    std::cout << "Sphere Pointer Surface Area: " << spherePtr->getSurfaceArea() << std::endl;
    delete cubePtr;
    delete spherePtr;   
    return 0;
}