#include "myBank.h"
#include <stdio.h>
float bankAccounts[50][2];
int maxNumberOfAccounts=50;


void faileToReadAccountNumber(int accountNumber){
    printf("\nFailed to read the amount");

}

int isAccountNumberLegal(int accountNumber){
    int flag=0;
    if(accountNumber > 950 || accountNumber < 901){
        printf("\nInvalid account number");
        return flag;

    }
    else if(bankAccounts[accountNumber-900][0]==0){
        printf("\nThis account is closed");
        flag=1;
        return flag;
    }
    return flag;
}

int isDepositLegal(float depositValue){
    int flag=0;
    if (depositValue <= 0 ){
            printf("\nInvalid Amount");
            return flag; 
        }
    else
    {
        flag=1;
        return flag;
    }
        

}

int isBankFull(){
    int bankFull=1;
    if(bankAccounts[50][0]==1){
        printf("\nOur bank is full");
        return bankFull;
    }
    else{
        bankFull=0;
        return bankFull;
    }
    
}



//open account function 01
void openAccount(float depositValue){

    int flag = isDepositLegal(depositValue);
    for (int x = 1; x < 51; x++) {
        if (bankAccounts[x][0] == (float)0){
            if (flag==1){
               //open account change to 1 as 1 is open 0 is closed 
               bankAccounts[x][0]= 1;    
               //in same row put the after opned put deposit value
               bankAccounts[x][1]= depositValue;
               printf("\nYour new account number is:%d",x+900);
               return;
            }
            else
            {
              return;
            }
        }
        else if(bankAccounts[50][0]==1){
            printf("\nwe dont have space for a new account");
            return;
        }
    }

}       




//checke balance function 02
void balanceInquiry(int accountNumber){
    float balance;
    if(accountNumber > 950 || accountNumber <901){
        printf("\nInvalid account number");

    }
    else if(bankAccounts[accountNumber-900][0]==0){
        printf("\nThis account is closed");
    }        
    else if(accountNumber <= 950 || accountNumber >= 901){
            //find the account number -900 because of indexing from 901-950
            printf("\nThe balance of account number:%d \nis: %.2f",accountNumber,balance=bankAccounts[accountNumber-900][1]);
    } 
    else
    {
        faileToReadAccountNumber(accountNumber);
    }
       
}



//Deposit function 03
void deposit(int accountNumber,float amount){

    if(accountNumber > 950 || accountNumber <901){
            printf("\nInvalid account number");
            return;
    }
    else if(bankAccounts[accountNumber-900][0]==0){
        printf("\nThis account is closed");
            return;

    }
    else if (amount <= 0 ){
            printf("\nInvalid Amount");
            return;
    } 
    //account is good to go 
    else if (accountNumber <= 950 && accountNumber >= 901){ 
            float balnce = bankAccounts[accountNumber-900][1];
            float newbalnce = balnce + amount;
            bankAccounts[accountNumber-900][1]=newbalnce;
            printf("\nYour new account balance is:%.2f",newbalnce);

    }
        else
    {
        faileToReadAccountNumber(accountNumber);
    }

}



//Withdrawl function 04
void withdrawl(int accountNumber,float amount){
    if(accountNumber > 950 || accountNumber <901){
            printf("\nInvalid account number");
            return;
    }
    else if(bankAccounts[accountNumber-900][0]==0){
        printf("\nThis account is closed");
            return;
    }
    else if (amount <= 0 ){
            printf("Invalid Amount");
            return;
    }
    else if(amount>bankAccounts[accountNumber-900][1]){
        printf("\nCannot withdraw more than the balance");
    }
     

    //account is good to go 
    else if (accountNumber <= 950 && accountNumber >= 901){
            float balnce = bankAccounts[accountNumber-900][1];
            float newbalnce = balnce - amount;
            bankAccounts[accountNumber-900][1]=newbalnce;
            printf("\nYour new account balance is:%.2f",newbalnce);     
    }
    else
    {
        faileToReadAccountNumber(accountNumber);
    }
    
}



//Close function 05
void close(int accountNumber){
    if(accountNumber > 950 || accountNumber <901){
            printf("\nInvalid account number");
            return;

    }

    else if(bankAccounts[accountNumber-900][0]==0){
        printf("\nThis account is closed");
            return;



    }

    //account is good to go 
    else if( 900 <= accountNumber &&  accountNumber <= 950 ){
            bankAccounts[accountNumber-900][0]=0;
            printf("\nYour account is now closed!");    
    }
    else
    {
            faileToReadAccountNumber(accountNumber);
    }

}


//Intrest function 06
void intrestForAll(float rate){
    if(rate<=0){
        printf("\nInvalid Amount");
        return;
    }


    for (int x = 1; x < 51; x++) {
        if (bankAccounts[x][0] != (float)0){
                bankAccounts[x][1]=bankAccounts[x][1]*(1+rate/100);
            

    
        }
    }
}            
  

void printAll(){
    int accountNumber;
    float accountBalance;
    for (int x = 1; x < 51; x++) {
        if (bankAccounts[x][0] != (float)0){
            printf("\nAccount number: %d  \nbalance %.2f",accountNumber = x+900,accountBalance = bankAccounts[x][1]);
        }
    }
} 

void closeAllAccounts(){
    for (int x = 1; x < 51; x++) {
        if (bankAccounts[x][0] == 1){
            bankAccounts[x][1]=0;
            bankAccounts[x][0]=0;
            
    
        }
    }
    printf("All accounts are now closed!");    


}
