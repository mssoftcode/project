#include <iostream>
#include <string>
#include "Product.h"
#include "Smartphone.h"
using namespace std;


Smartphone::Smartphone(){}
        
Smartphone::Smartphone(int productID, string nameOfProduct, double price, int monthsOfWarranty, 
        string operatingSystem, int batteryCapacity, bool waterproof, int numberOfSimCards) : 
        Product(productID, nameOfProduct, price, monthsOfWarranty), operatingSystem{operatingSystem},
        batteryCapacity{batteryCapacity}, waterproof{waterproof}, numberOfSimCards{numberOfSimCards}{}


Smartphone::~Smartphone(){}


void Smartphone::displayDetails(){
        cout << "------------------------------------------" << endl;
        cout << "Product ID: " << productID << endl;
        cout << "Name of product: " << nameOfProduct << endl;
        cout << "Price: " << price << endl;
        cout << "Months of warranty: " << monthsOfWarranty << endl;
        cout << "Operating system: " << operatingSystem << endl;
        cout << "Battery capacity: " << batteryCapacity << endl;
        cout << "Waterproof: " << boolalpha << waterproof << endl;
        cout << "Number of sim cards: " << numberOfSimCards << endl;
        cout << "------------------------------------------" << endl;

}

Smartphone* Smartphone::smartphoneCreator(){

    int productID, monthsOfWarranty, batteryCapacity, numberOfSimCards;
    string nameOfProduct, operatingSystem, processorType;
    double price;
    bool waterproof;
    char temp;

    cout << "Enter product ID: ";
    cin >> productID;
    cout << "Enter name of the product: ";
    getline(cin, nameOfProduct);
    getline(cin, nameOfProduct);
    cout << "Enter price of the product: ";
    cin >> price;
    cout << "Enter warranty period (in months): ";
    cin >> monthsOfWarranty;
    cout << "Enter operating system: ";
    getline(cin, operatingSystem);
    getline(cin, operatingSystem);
    cout << "Enter battery capacity (in mAh): ";
    cin >> batteryCapacity;
    cout << "Is smartphone water-resistant?(Y/N): ";
    cin >> temp;
    if(temp == 'Y' || temp == 'y') waterproof = true;
    else waterproof = false;
    cout << "Enter number of sim cards: ";
    cin >> numberOfSimCards;

    return new Smartphone(productID, nameOfProduct, price, monthsOfWarranty, operatingSystem, 
    batteryCapacity, waterproof, numberOfSimCards);
}