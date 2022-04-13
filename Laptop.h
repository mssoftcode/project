#ifndef LAPTOP_H
#define LAPTOP_H
#include "Product.h"
#include <string>
using namespace std;

class Laptop : public Product{

    public:
        Laptop();
        Laptop(int productID, string nameOfProduct, double price, int monthsOfWarranty, 
        string operatingSystem, string processorType, int hardDriveSize, int ramSize);
        ~Laptop();
        void displayDetails();
        static Laptop* laptopCreator();

    private:
        string operatingSystem;
        string processorType;
        int hardDriveSize;
        int ramSize;
};



#endif // LAPTOP_H