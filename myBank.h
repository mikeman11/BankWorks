#ifndef BANK__H
#define MY_BANK__H



void openAccount(float depositValue);
int isBankFull();
void balanceInquiry(int accountNumber);
void deposit(int accountNumber,float amount);
void withdrawl(int accountNumber,float amount);
void close(int accountNumber);
void intrestForAll(float rate);
void printAll();
void closeAllAccounts();

#endif // MY_BANK__H