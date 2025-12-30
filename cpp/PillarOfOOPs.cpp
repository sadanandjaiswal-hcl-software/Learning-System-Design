#include <bits/stdc++.h>
using namespace std;

// Abstraction
class Car{
    virtual void drive() = 0;
    virtual void brake() = 0;
    virtual void shiftgear(int gear) = 0;
    virtual void accelerate() = 0;
    
    // virtual ~Car(){};
};

// Inheritance
// Encapsulation
class SportsCar : public Car{
    private:
        string brand;
        string name;
        int speedometer;
        int gear;
        bool isRunning;
    
    public:
        
        SportsCar(string brand, string name){
            this->brand = brand;
            this->name = name;
            speedometer = 0;
            gear = 0;
            isRunning = false;
        }
        
        void drive(){
            this->isRunning = true;
            this->speedometer = 20;
            this->gear = 1;
            cout<<"Car is driving"<<endl;
        }
        
        void brake(){
            this->isRunning = false;
            this->speedometer = 0;
            this->gear = 0;
            cout<<"Car is stoped, speed = 0"<<endl;
        }
        
        void accelerate(){
            this->speedometer+=20;
        }
        
        void shiftgear(int gear){
            this->gear=gear;
        }
        
        // getter, setter
        
        
};

int main() {
	// your code goes here
	// Car is pointer : use ->
    SportsCar* car1 = new SportsCar("bmw", "ix20");
    car1->drive();
    car1->accelerate();
    car1->shiftgear(2);
    car1->accelerate();
    car1->brake();
    
    // Car is non pointer : use .
    SportsCar car2("mercedeze", "maybach");
    car2.drive();
    car2.accelerate();
    car2.shiftgear(2);
    car2.accelerate();
    car2.brake();
}
