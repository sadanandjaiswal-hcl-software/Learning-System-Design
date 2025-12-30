import java.util.*;
import java.lang.*;
import java.io.*;

// ************************ Abstraction and Encapsulation************************
// class Car{
// class should be abstract
abstract class Car{ 
    protected String brand;
    protected String model;
    protected boolean isEngineStart;
    protected int currentSpeed;
    
    public Car(String brand, String model){
        this.brand = brand;
        this.model = model;
        this.isEngineStart = false;
        this.currentSpeed = 0;
    }
    
    // java don't use destructure, it has garbage collector
    // public ~Car(){}
    
    public void startEngine(){
        isEngineStart = true;
        System.out.println(brand+" "+model+" : "+"Engine Started");
    }
    
    public void stopEngine(){
        isEngineStart = false;
        currentSpeed = 0;
        System.out.println(brand+" "+model+" : "+"Engine Stoped");
    }
    
    // ************************ Static Polymorphism (Compile time Polymorphism) : Method Overloading ************************
    abstract void accelerate();
    abstract void accelerate(int speed);

    abstract void brake();
};

// ************************ Inheritance & Dynamic Polymorphism (Run time Polymorphism) : Method Overriding ************************
class ManualCar extends Car{
    public int currentGear;
    
    public ManualCar(String brand, String model){
        super(brand, model);
        currentGear = 0;
    }
    
    // public Override accelerate(){
    @Override
    public void accelerate(){
        if(!isEngineStart){
            System.out.println(brand+" "+model+" : "+"Engine is off! cannot accelerate");
            return;
        }
        currentSpeed += 20;
        System.out.println(brand+" "+model+" : "+"Accelerating! current speed is "+currentSpeed);
    }
    
    @Override
    public void accelerate(int speed){
        if(!isEngineStart){
            System.out.println(brand+" "+model+" : "+"Engine is off! cannot accelerate");
            return;
        }
        currentSpeed += speed;
        System.out.println(brand+" "+model+" : "+"Accelerating! current speed is "+currentSpeed);
    }
    
    @Override 
    public void brake(){
        currentSpeed= currentSpeed>=20?currentSpeed-20:0;
        System.out.println(brand+" "+model+" : "+"Breaking! current speed is "+currentSpeed);
    }
    
    public void shiftGear(int gear){
        currentGear = gear;
        System.out.println(brand+" "+model+" : "+"Shifting gear, gear is "+currentGear);
    }
};

// ************************ Inheritance ************************
class ElectricCar extends Car{
    public int batteryLevel;   
    
    public ElectricCar(String brand, String model){
        super(brand, model);
        batteryLevel = 100;
    }
    
    // ************************ Method Overriding : Dynamic Polymorphism (Run time Polymorphism) ************************
    
    @Override
    public void accelerate(){
        if(!isEngineStart){
            System.out.println(brand+" "+model+" : "+"Engine is off! cannot accelerate");
            return;
        }
        currentSpeed += 15;
        batteryLevel = batteryLevel>=5?batteryLevel-5:0;
        System.out.println(brand+" "+model+" : "+"Accelerating! current speed is "+currentSpeed+", batteryLevel is "+batteryLevel+"%");
        
        if(batteryLevel<1){
            stopEngine();
        }
    }
    
    @Override
    public void accelerate(int speed){
        if(!isEngineStart){
            System.out.println(brand+" "+model+" : "+"Engine is off! cannot accelerate");
            return;
        }
        currentSpeed += speed;
        batteryLevel = batteryLevel>=5?batteryLevel-5:0;
        System.out.println(brand+" "+model+" : "+"Accelerating! current speed is "+currentSpeed+", batteryLevel is "+batteryLevel+"%");
        
        if(batteryLevel<1){
            stopEngine();
        }
    }
    
    @Override 
    public void brake(){
        currentSpeed= currentSpeed>=20?currentSpeed-15:0;
        System.out.println(brand+" "+model+" : "+"Breaking! current speed is "+currentSpeed);
    }
    
    public void chargeBattery(){
        batteryLevel+=10;
        if(batteryLevel>100) batteryLevel=100;
        System.out.println(brand+" "+model+" : "+"Battery Chargin!! current battery is "+batteryLevel+"%");
    }
};


class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		
		// java don't have pointers
// 		ManualCar* car1 = new ManualCar("Maruti Suzuki", "Wagonar");
		ManualCar car1 = new ManualCar("Maruti Suzuki", "Wagonar");
        car1.startEngine();
        car1.shiftGear(1);
        car1.accelerate();
        car1.accelerate();
        car1.brake();
        car1.accelerate();
        car1.brake();
        car1.stopEngine();
        
        System.out.println("____________________________________");
        
        // This is wrong in java
        // ElectricCar car2("Tesla", "Model S");
        ElectricCar car2 = new ElectricCar("Tesla", "Model S");
        car2.startEngine();
        car2.chargeBattery();
        car2.accelerate();
        car2.chargeBattery();
        car2.accelerate();
        car2.chargeBattery();
        car2.brake();
        car2.startEngine();

	}
}
