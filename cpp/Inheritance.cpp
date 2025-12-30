#include <bits/stdc++.h>
using namespace std;

class Car{
  protected:
    string brand;
    string model;
    bool isEngineStart;
    int currentSpeed;
  
  public:
    Car(string brand, string model){
        this->brand = brand;
        this->model = model;
        this->isEngineStart = false;
        this->currentSpeed = 0;
    }
    
    ~Car(){}
    
    void startEngine(){
        isEngineStart = true;
        cout<<brand<<" "<<model<<" : "<<"Engine Started\n";
    }
    
    void stopEngine(){
        isEngineStart = false;
        currentSpeed = 0;
        cout<<brand<<" "<<model<<" : "<<"Engine Stoped\n";
    }
    
    void accelerate(){
        if(!isEngineStart){
            cout<<brand<<" "<<model<<" : "<<"Cannot accelerate, engine is off!!\n";
        }
        else currentSpeed+= 20;
        cout<<brand<<" "<<model<<" : "<<"accelerating! speed is now "<<currentSpeed<<endl;
    }
    
    void brake(){
        currentSpeed = currentSpeed<20?0:currentSpeed-20;
        cout<<brand<<" "<<model<<" : "<<"breaking! speed is now "<<currentSpeed<<endl;
    }
};

class ManualCar : public Car{
  public:
    int currentGear;
    
    ManualCar(string brand, string model) : Car(brand, model){
        currentGear = 0;
    }
    
    void shiftGear(int gear){
        currentGear = gear;
        cout<<brand<<" "<<model<<" : "<<"shiffted to gear "<<currentGear<<endl;
    }
};

class ElectricCar : public Car{
  public:
    int batteryLevel;
    
    ElectricCar(string brand, string model) : Car(brand, model){
        batteryLevel = 100;
    }
    
    void chargeBattery(){
        batteryLevel= batteryLevel<=80?batteryLevel+20:100;
        if(batteryLevel==100){
            cout<<brand<<" "<<model<<" : "<<"battery is fully charged!"<<endl;
        }
    }
};

int main() {
	// your code goes here
    ManualCar* car1 = new ManualCar("Maruti Suzuki", "Wagonar");
    car1->startEngine();
    car1->shiftGear(1);
    car1->accelerate();
    car1->accelerate();
    car1->brake();
    car1->accelerate();
    car1->brake();
    car1->stopEngine();
    
    cout<<endl<<endl;
    
    ElectricCar car2("Tesla", "Model S");
    car2.startEngine();
    car2.chargeBattery();
    car2.accelerate();
    car2.accelerate();
    car2.brake();
    car2.startEngine();
}
