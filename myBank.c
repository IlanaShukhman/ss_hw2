#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"
#define numAccounts 50
#define Balance 2

double accounts[numAccounts][Balance]={0};

//check if the account number is legal and open
bool check(int num){
  if(num<0 || num>49){
    printf("The input is not legal, please try again.\n");
    return false;
  }
  else if(accounts[num][0]==0){
    printf("This account is not open. Please open the account first.\n");
    return false;
  }
  return true;
}

//to open the account, need an initial amount.
void openAccount(double amount){
  int i=0;
  while(accounts[i][0]==1 && i<numAccounts)
    i++;
  if(i==numAccounts){
    printf("The maximum number of accounts are open. Cannot open more.\n");
    return;
  }
  accounts[i][0]=1;
  accounts[i][1]=amount;
  printf("The number of your account is: %d and has in it: %0.2lf Shekels\n", i+901, accounts[i][1]);
}

//this function returns the balance in a given account
void balance(int account_number){
  account_number-=901;
  bool isInputLegal=check(account_number);
  if(isInputLegal==false)
    return;
  printf("The balance in the account is: %0.2lf\n", accounts[account_number][1]);
}

void deposit(int account_number, double amount){
  account_number-=901;

  bool isInputLegal=check(account_number);
  if(isInputLegal==false)
    return;

  if(amount<0){
    printf("Not in the right function. Please try again.\n");
    return;
  }
  accounts[account_number][1]+=amount;
  printf("The current balance in the account is: %0.2lf\n", accounts[account_number][1]);
}

void withdraw(int account_number, double amount){
  account_number-=901;

  bool isInputLegal=check(account_number);
  if(isInputLegal==false)
    return;

  if(accounts[account_number][1]<amount){
    printf("Cannot withdraw more than you have. Please try again with a smaller amount.\n");
    return;
  }

  if(amount<=0){
    printf("Not a legal input. Please try again.\n");
  }

  accounts[account_number][1]-=amount;
  printf("The current balance in the account is: %0.2lf\n", accounts[account_number][1]);
}

void closeAccount(int account_number){
  account_number-=901;

  bool isInputLegal=check(account_number);
  if(isInputLegal==false)
    return;

  if(accounts[account_number][0]==0){
    printf("The account is already closed.\n");
    return;
  }
  accounts[account_number][0]=0;
  accounts[account_number][1]=0;
}

void addInterestRate(double interestRate){
  if(interestRate<0){
    printf("The input is not legal. please try again.\n");
    return;
  }
  int i;
  for(i=0;i<numAccounts;i++){
    if(accounts[i][0]==1){
      accounts[i][1]=accounts[i][1]*(1+interestRate/100);
    }
  }
}

void print(){
  int i;
  for (i=0;i<numAccounts;i++){
    if(accounts[i][0]==1)
    printf("The account is %d and has %0.2lf Shekels in it.\n", i+901 ,accounts[i][1] );
  }
}

void Exit(){
  int i;
  for(i=0; i<numAccounts; i++){
    accounts[i][0]=0;
    accounts[i][1]=0;
  }
}
