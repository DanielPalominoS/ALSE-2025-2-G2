#include <iostream>
using namespace std;

// Defining a Vehicle class
class Vehicle { 
private:
    int speed; // Encapsulated attribute
    string brand; // Encapsulated attribute
    //int wheels; // Encapsulated attribute
public:   
    // Constructor
    Vehicle(string b, int s) : brand(b), speed(s) {}
    Vehicle(string b): brand(b){
        speed=0;
    }    
    Vehicle(int  s){
        speed=s;
        brand="Generic";
    }
    //Poimnt3d p1();
    //Point3d p2(1.0, 2.0, 3.0);
    // Destructor
    virtual ~Vehicle() {
        // Destructor logic (if any)
        cout << "Vehicle object with brand " << brand << " is being destroyed." << endl;
    }
    // Getter for speed
    int getSpeed() const {
        return speed;
    }
    // Setter for speed
    void setSpeed(int s) {
        if (s < 0) {
            cout << "Speed cannot be negative. Setting to 0." << endl;
            speed = 0; // Ensure speed is non-negative
        } else {
            speed = s;
        }
    }
    string getBrand() const {
        return brand;
    }
    void setBrand(string b) {
        brand = b;
    }
    // Public method
    virtual void display() {
        //cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << "# wheels"<< endl;
    }
};

int main() {
    Vehicle car1("Toyota", 120);
    Vehicle car2(3.0);
    Vehicle car3("Renault");
    //car3.brand="Ford";
    Vehicle car4();
    car3.setSpeed(90);
    car4=car1;
    car1.display();
    car2.display();
    //car3.brand="Toyota";
    return 0;
}
