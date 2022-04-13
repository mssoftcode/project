#ifndef PENDRIVE_H
#define PENDRIVE_H

#include "Product.h"
using namespace std;



class Pendrive : public Product{
    public:
        Pendrive(int productID, string nameOfProduct, double price, int monthsOfWarranty, int storageSpace);
        void displayDetails() override;
        static Pendrive* pendriveCreator();

    private:
        int storageSpace;
};

#endif // PENDRIVE_H