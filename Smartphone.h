#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "Product.h"
#include <string>

class Smartphone : public Product{
    public:
        Smartphone();
        Smartphone(int productID, string nameOfProduct, double price, int monthsOfWarranty, 
        string operatingSystem, int batteryCapacity, bool waterproof, int numberOfSimCards);
        ~Smartphone();
        void displayDetails();
        static Smartphone* smartphoneCreator();
    private:
        string operatingSystem;
        int batteryCapacity;
        bool waterproof;
        int numberOfSimCards;
};

#endif // SMARTPHONE_H