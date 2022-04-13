#ifndef PRODUCT_H
#define PRODUCT_H


using namespace std;

class Product{
    public:
        Product();
        Product(int productID, string nameOfProduct, double price, int monthsOfWarranty);
        virtual ~Product();
        virtual void displayDetails() = 0;
        long long int productID;
    
    protected:
        string nameOfProduct;
        double price;
        int monthsOfWarranty;   
        double getPrice() const;
        int getMonthsOfWarranty() const;
        string getNameOfProduct() const;
};

#endif //PRODUCT_H