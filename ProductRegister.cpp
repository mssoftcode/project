#include <iostream>
#include "ProductRegister.h"
#include "Product.h"
using namespace std;

ProductRegister* ProductRegister::productRegister = nullptr;

ProductRegister* ProductRegister::getProductRegister(){
    if(productRegister == nullptr) return new ProductRegister();
    else return productRegister;
}
//ProductRegister::ProductRegister(){};

void ProductRegister::addProduct(Product *product){
    listOfProducts.push_back(product);
}

void ProductRegister::showAllProducts(){
    if(listOfProducts.size() == 0) cout << "No products." << endl;
    for(int i=0; i<listOfProducts.size(); i++) listOfProducts[i]->displayDetails();
}

void ProductRegister::deleteProduct(int productCode){
    // for(int i=0; i<listOfProducts.size(); i++){
    //     if(listOfProducts[i]->productID == productCode) listOfProducts.erase(i);
    // }
}


