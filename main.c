#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "myBank.h"
#define n 50

double amount;
double account_number;

int main(){
  char type;
  bool stay=true;

  while(stay){

    printf("Transaction type? \n");
    scanf(" %c", &type);

    switch(type)
    {
    case 'O':
       printf("Initial deposit? \n");
       scanf("%lf", &amount);
       openAccount(amount);
       break;

    case 'B':
       printf("Account number? \n");
       scanf("%lf", &account_number);
       balance(account_number);
       break;

    case 'D':
       printf("Account number? \n");
       scanf("%lf", &account_number);
       printf("Amount? \n");
       scanf("%lf", &amount);
       deposit(account_number, amount);
       break;

    case 'W':
       printf("Account number? ");
       scanf("%lf", &account_number);
       printf("Amount? ");
       scanf("%lf", &amount);
       withdraw(account_number,amount);
       break;

    case 'C':
       printf("Account number? \n");
       scanf("%lf", &account_number);
       closeAccount(account_number);
       break;

    case 'I':
       printf("Interest rate? \n");
       double interestRate;
       scanf("%lf", &interestRate);
       addInterestRate(interestRate);
       break;

    case 'P':
       print();
       break;

    case 'E':
       Exit();
       stay=false;
       break;

    default:
    printf("Not according the options.\n");
   }
  }
  return 0;
}
