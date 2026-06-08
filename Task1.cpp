//
// Created by acer_ on 08.06.2026.
//
#include "Task1.h"
#include <iostream>
#include <string>
#include <vector>

class TransportVehicle {
protected:
    std::string brand;
    int maxSpeed;

public:
    TransportVehicle(const std::string& b, int speed) : brand(b), maxSpeed(speed) {}
    
    virtual ~TransportVehicle() {}
    
    virtual void printInfo() const {
        std::cout << "Transport vehicle: " << brand << ", Max speed: " << maxSpeed << " km/h" << std::endl;
    }
};

class Car : public TransportVehicle {
private:
    int doorCount;

public:
    Car(const std::string& b, int speed, int doors) 
        : TransportVehicle(b, speed), doorCount(doors) {}

    ~Car() override {}

    void printInfo() const override { //перевизначати
        TransportVehicle::printInfo();
        std::cout << " [Type: car, door count: " << doorCount << "]" << std::endl;
    }
};

class Truck : public TransportVehicle {
private:
    double loadCapacity;

public:
    Truck(const std::string& b, int speed, double capacity) 
        : TransportVehicle(b, speed), loadCapacity(capacity) {}

    ~Truck() override {}

    void printInfo() const override {
        TransportVehicle::printInfo();
        std::cout << " [Type: Truck, Capacity: " << loadCapacity << " tonne]"<< std::endl;
    }
};

class Steamship : public TransportVehicle {
private:
    double displacement;

public:
    Steamship(const std::string& b, int speed, double disp) 
        : TransportVehicle(b, speed), displacement(disp) {}

    ~Steamship() override {}

    void printInfo() const override {
        TransportVehicle::printInfo();
        std::cout << " [Type: Steamship, displacement: " << displacement << " tonne]" <<std::endl;
    }
};

class Plane : public TransportVehicle {
private:
    int maxAltitude;

public:
    Plane(const std::string& b, int speed, int altitude) 
        : TransportVehicle(b, speed), maxAltitude(altitude) {}

    ~Plane() override {}

    void printInfo() const override {
        TransportVehicle::printInfo();
        std::cout << " [Type: Plane, Max. altitude: " << maxAltitude << " m]" << std::endl;
    }
};

int main() {
    std::vector<TransportVehicle*> list;

    TransportVehicle* car = new Car("BMW M5", 250, 4);
    list.push_back(car);
    TransportVehicle* truck = new Truck("Man", 250, 2);
    list.push_back(truck);
    TransportVehicle* steamship = new Steamship("Steam", 250, 2);
    list.push_back(steamship);
    TransportVehicle* plane = new Plane("Boeing", 250, 10000);
    list.push_back(plane);

    for (int i = 0; i < list.size(); ++i) {
        TransportVehicle* vehicle = list[i];
        vehicle->printInfo();


    }

    return 0;
}