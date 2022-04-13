#ifndef TRANSACTION_REGISTER_H
#define TRANSACTION_REGISTER_H
#include "Product.h"
#include "ProductRegister.h"
using namespace std;




class TransactionRegister{
    public:
        static TransactionRegister* getTransactionRegister();
        void addTransaction(Product *product, ProductRegister* productRegister);
        void showAllTransactions();
        void deleteTransaction();
        bool isEmpty();
    private:

        // wewnetrzna klasa umozliwiajaca tworzenie pojedynczych transakcji
        class Transaction{
            public:
                Transaction(Product *product);
                ~Transaction(){};
                void printTransactionDetails();
                static int numberOfTransactions;
                int transactionID;
                Product *product;
                Transaction *next;
        };
        TransactionRegister();
        ~TransactionRegister(){};
        TransactionRegister::Transaction *firstTransaction, *lastTransaction;
        static TransactionRegister* transactionRegister;

};

#endif // TRANSACTION_REGISTER_H