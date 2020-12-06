#include <stdio.h>
#include <stdbool.h>

#include "myBank.h"

void usage(){
    printf("Invalid transaction type");
}

int main(void){
    char userInput;
    bool quit = false;
    
    while(!quit){
        printf("\n\nO Open Account\nB Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print E-Exit");
        printf("\n\n");
        printf("Please choose a transaction type:");//list of commands
        printf("\n");
        //printf("\n list of commands");

        scanf(" %c", &userInput);
        switch(userInput)
        {
            case 'E':
            {   
                printf("We are closing all the accounts please wait");
                quit=true;
                break;
            }    

            case 'O':
            {
                int bankfull;
                bankfull=isBankFull();
                if(bankfull==0){
                    
                    float depositValue=0.0;
                    printf("Please enter amount for deposit:");
                    scanf("%f", &depositValue);
                    openAccount(depositValue);
                    break;
                }
            
            }    

            case 'B':
            {    
                int accountNumber=0;
                printf("Please enter account number:");
                scanf("%d", &accountNumber);
                balanceInquiry(accountNumber);
                break;
            }    
       
            case 'D':
            { 
                int accountNumber=0;
                float depositValue=0.0;
                printf("Please enter account number:");
                scanf("%d", &accountNumber);
                printf("Please enter the amount to deposit:");
                scanf("%f", &depositValue);
                deposit(accountNumber,depositValue);
                break;
            }    

            case 'W':
            { 
                int accountNumber=0;
                float depositValue=0.0;
                printf("Please enter account number:");
                scanf("%d", &accountNumber);
                printf("Please enter the amount to withdraw:");
                scanf("%f", &depositValue);

                withdrawl(accountNumber,depositValue);
                break;
            }    
                

            case 'C':
            { 
                int accountNumber=0;
                printf("Please enter account number:");
                scanf("%d", &accountNumber);
                close(accountNumber);
                break;
            }    


            case 'I':
            { 
                float rate;
                printf("What is the rate of intrest?");
                scanf("%f", &rate);
                intrestForAll(rate);
                break;
            }    

            case 'P':
            { 
                printAll();
                break;
            }    
        
            default:
            {
                usage();
            }
        }
    }
    return 0;
}