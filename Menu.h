#ifndef MENU_H
#define MENU_H

#include "Product.h"
#include "TransactionRegister.h"
#include "ProductRegister.h"
using namespace std;


class Menu{

    public:
        static void displayMainMenu();
        static void executeUserChoice(int userChoice);
        static Product* createProductMenu();
        static Product* executeProductChoice(int userChoice);
    private:
        static TransactionRegister* transactionRegister;
        static ProductRegister* productRegister;


};



#endif // MENU_H