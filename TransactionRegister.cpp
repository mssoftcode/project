#include <iostream>
#include "TransactionRegister.h"
#include "Product.h"
#include "ProductRegister.h"
using namespace std;

// definicja i inicjalizacja liczby transakcji (skladnik statyczny)
int TransactionRegister::Transaction::numberOfTransactions = 0;

// definicja i inicjalizacja zmiennej rejestr transakcji (skladnik statyczny)
TransactionRegister* TransactionRegister::transactionRegister = nullptr;

// utworzenie pojedynczego obiektu klasy "rejestr transakcji"
// zgodnie ze wzorcem projektowym "SINGLETON"
// statyczna funkcja skladowa
TransactionRegister* TransactionRegister::getTransactionRegister(){
    if(transactionRegister == nullptr) return new TransactionRegister();
    else return transactionRegister;
}


// konstruktor klasy "rejestr transakcji"
// ustawienie wskaznikow listy wiazanej na nullptr
TransactionRegister::TransactionRegister(){
    firstTransaction = nullptr;
    lastTransaction = nullptr;
}


// konstruktor klasy "transakcja"
// odpowiednie ustawienie wskaznikow
TransactionRegister::Transaction::Transaction(Product *product){
    this->product = product;
    this->next = nullptr;
    this->transactionID = ++numberOfTransactions;
}

// dodawanie transakcji do rejestru transakcji
void TransactionRegister::addTransaction(Product *product, ProductRegister* productRegister){

    // utworzenie nowej transakcji z przekazanym produktem
    TransactionRegister::Transaction* transaction = new TransactionRegister::Transaction(product);

    // ustawienie wskaznikow zgodnie z idea listy wiazanej
    if(firstTransaction == nullptr){
        firstTransaction = transaction;
        lastTransaction = transaction;
    }else{
        lastTransaction->next = transaction;
        lastTransaction = lastTransaction->next;
    }
    productRegister->addProduct(product);
}



// wyswietlanie informacji o transakcji
void TransactionRegister::Transaction::printTransactionDetails(){
    cout << "TransactionID: " << transactionID << endl;
    product->displayDetails();
}


// wyswietlenie wszystkich transakcji
void TransactionRegister::showAllTransactions(){
    if(isEmpty()) return;

    Transaction* transaction = firstTransaction;
    while(transaction != nullptr){
        transaction->printTransactionDetails();
        transaction = transaction->next;
    }
}


bool TransactionRegister::isEmpty(){
    if(firstTransaction == nullptr) {
        cout << "There are no transactions." << endl;
        return true;
    }else{
        return false;
    }
}




void TransactionRegister::deleteTransaction(){
    int transactionNumber;
    cout << "Enter number of transaction to removed: ";
    cin >> transactionNumber;
    Transaction* currentTransaction = firstTransaction;
    Transaction* toErase;

    if(isEmpty()) return;

    if(currentTransaction->next == nullptr && currentTransaction->transactionID == transactionNumber){
        firstTransaction = firstTransaction->next;
        delete currentTransaction;
        cout << "Transaction number "<< transactionNumber << " has been removed." << endl;
        return;
    }


    Transaction* previousTransaction = currentTransaction;
    currentTransaction = currentTransaction->next;



    while(currentTransaction != nullptr){
        if(currentTransaction->transactionID == transactionNumber){
            toErase = currentTransaction;
            previousTransaction->next = currentTransaction->next;
            currentTransaction = currentTransaction->next;
            delete toErase;
            cout << "Transaction number "<< transactionNumber << " has been removed." << endl;
            break;
        }
        previousTransaction = currentTransaction;
        currentTransaction = currentTransaction->next;
    }
    cout << "Transaction number "<< transactionNumber << " is not listed in the register." << endl;
}

