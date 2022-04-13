#include <iostream>
#include "Pendrive.h"
#include "Product.h"
using namespace std;


Pendrive::Pendrive(int productID, string nameOfProduct, double price, int monthsOfWarranty, int storageSpace)
: Product(productID, nameOfProduct, price, monthsOfWarranty), storageSpace{storageSpace}{}


void Pendrive::displayDetails(){
    cout << "------------------------------------------" << endl;
    cout << "Product ID: " << productID << endl;
    cout << "Name of product: " << nameOfProduct << endl;
    cout << "Price: " << price << endl;
    cout << "Months of warranty: " << monthsOfWarranty << endl;
    cout << "Storge space (in GB): " << storageSpace << endl;
    cout << "------------------------------------------" << endl;
}


// funkcja statyczna do tworzenia obiektu wraz z menu
Pendrive* Pendrive::pendriveCreator(){
    int productID, monthsOfWarranty, storageSpace;
    string nameOfProduct; 
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
    cout << "Enter storage space (in GB): ";
    cin >> storageSpace;
    return new Pendrive(productID,nameOfProduct,price,monthsOfWarranty,storageSpace);
}