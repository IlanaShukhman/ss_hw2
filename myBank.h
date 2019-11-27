#ifndef MYBANK
#define MYBANK

void openAccount(double amount);

void balance(int account_number);

void deposit(int account_number, double amount);

void withdraw(int account_number, double amount);

void closeAccount(int account_number);

void addInterestRate(double interestRate);

void print();

void Exit();

#endif
