#include <iostream>
#include "Laptop.h"
#include "Product.h"
using namespace std;


Laptop::Laptop(){};

Laptop::Laptop(int productID, string nameOfProduct, double price, int monthsOfWarranty, 
        string operatingSystem, string processorType, int hardDriveSize, int ramSize) : 
        Product(productID, nameOfProduct, price, monthsOfWarranty), operatingSystem{operatingSystem},
        processorType{processorType}, hardDriveSize{hardDriveSize}, ramSize{ramSize}{}

Laptop::~Laptop(){}


void Laptop::displayDetails(){
        cout << "------------------------------------------" << endl;
        cout << "Product ID: " << productID << endl;
        cout << "Name of product: " << nameOfProduct << endl;
        cout << "Price: " << price << endl;
        cout << "Months of warranty: " << monthsOfWarranty << endl;
        cout << "Operating system: " << operatingSystem << endl;
        cout << "Processor type: " << processorType << endl;
        cout << "Hard drive size: " << hardDriveSize << endl;
        cout << "Ram size: " << ramSize << endl;
        cout << "------------------------------------------" << endl;
}

// funkcja statyczna do tworzenia obiektu wraz z menu
Laptop* Laptop::laptopCreator(){
    int productID, monthsOfWarranty, storageSpace, hardDriveSize, ramSize;
    string nameOfProduct, operatingSystem, processorType;
    double price;

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
    cout << "Enter processor type: ";
    getline(cin, processorType);
    cout << "Enter hard drive size (in GB): ";
    cin >> hardDriveSize;
    cout << "Enter ram size in GB: ";
    cin >> ramSize;

    return new Laptop(productID,nameOfProduct,price,monthsOfWarranty, 
    operatingSystem, processorType, hardDriveSize, ramSize);
}