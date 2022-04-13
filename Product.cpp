#include <string>
#include "Product.h"
using namespace std;


Product::Product(int productID, string nameOfProduct, double price, int monthsOfWarranty)
: productID{productID}, nameOfProduct{nameOfProduct}, price{price}, monthsOfWarranty{monthsOfWarranty}{}

Product::Product(){};
Product::~Product(){};

double Product::getPrice() const { return price; }
int Product::getMonthsOfWarranty() const { return monthsOfWarranty; }
string Product::getNameOfProduct() const { return nameOfProduct; }