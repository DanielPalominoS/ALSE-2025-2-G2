#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:  
    
    Complex(double r, double i) : real(r), imag(i) {}

    // Overloading the '+' operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
    void setReal(double r) {
        real = r;
    }
    double getReal() {
        return real;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    //c1.real = 5; // Direct access to public member
    c1.setReal(5);
    c1.display();
    c2.display();
    Complex sum = c1 + c2;
    sum.display();
    cout<<"c2.real: "<<c2.getReal()<<  endl;
    return 0;
}
