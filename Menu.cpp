#include <iostream>
#include "Laptop.h"
#include "Menu.h"
#include "Pendrive.h"
#include "Smartphone.h"
#include "TransactionRegister.h"
#include "ProductRegister.h"
using namespace std;

TransactionRegister* Menu::transactionRegister = TransactionRegister::getTransactionRegister();
ProductRegister* Menu::productRegister = ProductRegister::getProductRegister();

void Menu::displayMainMenu(){
    int userChoice;
        cout << "HELLO!" << endl;
    do{
        cout << endl;
        cout << "What woud you like to do?" << endl;
        cout << "1. Display products" << endl;
        cout << "2. Create product" << endl;
        cout << "3. Delete transaction" << endl;
        cout << "4. Display all transactions" << endl;
        cout << "5. Quit" << endl;
        cout << "Your choice: ";
        cin >> userChoice;
        if(userChoice < 1 || userChoice > 5) {
            cout << "Incorrect option." << endl;   
            continue;
        }
        Menu::executeUserChoice(userChoice);
    }while(userChoice != 5);
}

void Menu::executeUserChoice(int userChoice){
    switch(userChoice){
        case 1:
            productRegister->showAllProducts();
            break;
        case 2:
            transactionRegister->addTransaction(Menu::createProductMenu(), productRegister);
            break;
        case 3:
            transactionRegister->deleteTransaction();
            break;
        case 4:
            transactionRegister->showAllTransactions();
            break;
        case 5:
            cout << "Good Bye." << endl;
            break;
        default:
            cout << "Incorrect option" << endl;
            break;
    }
}


Product* Menu::createProductMenu(){
    int userChoice;
    cout << "What kind of product do you want to create?" << endl;
    cout << "1. Pendrive" << endl;
    cout << "2. Laptop" << endl;
    cout << "3. Smrtphone" << endl;
    cout << "4. Refrigerator (NOT IMPLEMENTED)" << endl;
    cout << "5. Washing machine (NOT IMPLEMENTED)" << endl;
    cout << "Your choice: ";
    cin >> userChoice;
    return Menu::executeProductChoice(userChoice);
}


// wzorzec projektowy - METODA WYTWORCZA
// tworzy instancje odpowiedniego typu
Product* Menu::executeProductChoice(int userChoice){
    switch(userChoice){
        case 1:
            return Pendrive::pendriveCreator();
            break;
        case 2:
            return Laptop::laptopCreator();
            break;
        case 3:
            return Smartphone::smartphoneCreator();
            break;
        default:
            return nullptr;
            break;
    }

}