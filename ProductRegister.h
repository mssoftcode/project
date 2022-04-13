#ifndef PRODUCT_REGISTER_H
#define PRODUCT_REGISTER_H
#include <vector>
#include "Product.h"
using namespace std;




class ProductRegister{
    public:
        static ProductRegister* getProductRegister();
        void addProduct(Product *product);
        void showAllProducts();
        void deleteProduct(int productCode);

    private:
        ProductRegister(){};
        ~ProductRegister(){};
        static ProductRegister* productRegister;
        vector<Product*> listOfProducts;

};





#endif // PRODUCT_REGISTER_H