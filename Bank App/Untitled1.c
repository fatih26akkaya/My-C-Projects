#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>

int balance;

int menu()
{
    system("cls");

    int choice;
    printf("\nATM APP\n");
    printf("1-Withdraw Money\n");
    printf("2-Deposit Money\n");
    printf("3-Pay Bill\n");
    printf("4-Transfer/EFT\n");
    printf("5-Exit\n");
    return choice;
}

void withdrawMoney()
{
    int quantity;
    printf("Quantity : "); scanf("%d", quantity);
    if(balance < quantity)
    {
        printf("Insufficent Balance\n");
    }
    else
    {
        balance -= quantity;
        printf("Withdrawl Successful\n");
        printf("Don't Forget to Get Your Card\n");
    }
    printf("You Are Redirected to The Main Menu...\n");
}

 void depositMoney()
 {
     int quantity;
     printf("Enter The Amount to Deposit : "); scanf("%d", &quantity);
     balance += quantity;
     printf("Your Transection is Being Processed\n");
     printf("Deposit Successful\n");

     printf("You Are Redirected to The Main Menu...\n");
 }

 void payBill()
 {
     int quantity, choice, no;
     printf("1-Electricity\n");
     printf("2-Water\n");
     printf("3-Natural Gas\n");
     printf("4-Telephone\n");
     scanf("%d", &choice);
     if(choice > 4 || choice < 1)
     {
         printf("You Made The Wrong Choice\n");
     }
     else
     {
         printf("Invoice No : "); scanf("%d", no);
         quantity = rand() % 1000 + 0;
         printf("Invoice Amount Belonging to Fatih Akkaya Person : %d\n", quantity);
         printf("1-I Confirm Payment"); scanf("%d", &choice);
         if(choice != 1)
         {
            printf("Transaction is Canceled");
         }
         else
         {
             balance -= quantity;
             printf("Your Transaction is Being Processed...\n");
             printf("Payment Successful\n");
         }
         printf("You Are Redirected to The Main menu...\n");
     }
 }

void remittanceEFT()
{
    int quantity, no;
    printf("Iban Number of Person to Be Remitted : "); scanf("%d", &no);
    printf("Amount to Be Transferred : "); scanf("%d", &quantity);

    if(balance < quantity)
    {
        printf("Insufficent Balance\n");
    }
    else
    {
        balance -= quantity;
        printf("Transfer is Being Processed...\n");
        printf("Transfer Successful\n");
    }
    printf("You Are Redirected to The Main Menu...\n");
}

int main()
{
    int password,i=0;
    printf("Enter Your Password : "); scanf("%d", password);
    while(password != 8264)
    {
        printf("You Entered The Wrong Password,Enter Your Password : ");
        scanf("%d", password);
        if(i == 3)
        {
            printf("Your Card is Locked\n");
            printf("Please Contact Customer Service\n");
        }
        i++;
    }

    srand(time(0));
    balance = rand() % 1000 + 0;

    int choice = menu();
    switch(choice)
    {
        case 1: withdrawMoney(); break;
        case 2: depositMoney(); break;
        case 3: payBill(); break;
        case 4: remittanceEFT(); break;
        case 5: printf("Don't Forget to Get Your Card...\n"); return 0;
        default : printf("You Made The Wrong Choice\n");
    }
}

