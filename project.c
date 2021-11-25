#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>


int menu_input();
void menu();
void menuLogin();
void login();
void current_acc_header();//
void creatingAcc();
void display();
void displayMenu();
void withdrawal();
void deposit();
void display_account_summary();
void clear_screen();
void add_percent();



struct Bank_account
{
    char CIN[20];
    char first_name[20];
    char last_name[20];
    float current_amount;
}accounts[255];


int current_bank_account = 0;
int bank_accounts_count = 0;

int main(){
    clear_screen();
    while (true)
        {
        int choice;

        menu();

        scanf("%d",&choice);

        switch(choice){
            case 1:
                clear_screen();
                creatingAcc();
                break;
            case 2:
                clear_screen();;
                login();
                break;
            case 3:
                clear_screen();
                display();
                break;
            case 4:
                clear_screen();
                add_percent();
                break;
            case 0:
                exit(0);
                break;
            default:
                clear_screen();
                printf("\nPlease choose a valid option.\n\n");

        }
    }

    return 0;
}
void menu()
{
    printf("//______Welcome to your bank service!______//\n \n \n");
    printf("Current options:\n \n");
    printf("1 - Register a new account.\n");
    printf("2 - Login by CIN.\n");
    printf("3 - View your accounts.\n");
    printf("4 - Include 1.3%% bonus for the first 3 accounts.\n");
    printf("0 - Exit.\n\n");
    printf("//__State your choice:__//\n");
}

void creatingAcc()
{
    char CIN[20];
    int i;
    clear_screen();
    printf("\n//______Adding a new bank account______//\n\n");
    printf("\nEnter CIN: \n\n");
    scanf("%s",&CIN);
        for(i=0;i<bank_accounts_count;i++);
            if(accounts[i].CIN == CIN)
        {
            {
                printf("\nCIN %d already exists\n",CIN);
                return;
            }
        }
    strcpy(accounts[bank_accounts_count].CIN, CIN);
    printf("\nEnter your first name:\n\n");
    scanf("%s",accounts[bank_accounts_count].first_name);
    printf("\nEnter your last name:\n\n");
    scanf("%s",accounts[bank_accounts_count].last_name);
    bank_accounts_count++;
    clear_screen();
    printf("\n//______The Bank account was added successfully!______//\n\n");

    }

void login()
{
    int menu_item;
    int exit = 0;
    char CIN_input[20];
    int i = 0;
    clear_screen();
    printf("//__________Login__________//\n");
    printf("\nEnter CIN: ");
    scanf("%s",&CIN_input);
    int found = 0;

    for(i=0;i<bank_accounts_count;i++)
    {
        if(strcmp(accounts[i].CIN,CIN_input) == 0)
        {
            current_bank_account = i;
            found = 1;
            break;
        }
    }
    if(found == 0)
    {
        //clear_screen();
        printf("\nAccount was not found!\n");
    }
    else
    {
        current_account_header();
        while(true)
        {
            int choice;
            menuLogin();

            scanf("%d",&choice);

            switch(choice)
            {
            case 1:
                withdrawal();
                break;
            case 2:
                deposit();
                break;
            case 3:
                display_account_summary();
                break;
            case 0:
                exit = 1;
                break;
            default:
                printf("\nPlease choose another option!");
                break;

            }

            if(exit == 1)
            {
                break;
            }


        }

    }

}

void menuLogin()
{
    printf("\n//_______Account Menu_______//\n");
    printf("\n 1 - Withdrawal");
    printf("\n 2 - Deposit");
    printf("\n 3 - Display account summary");
    printf("\n 0 - Return to the main menu");
    printf("\n//__________________________//\n\n");
}

void current_account_header()
{
    clear_screen();
    printf("Current account: %s\n", accounts[current_bank_account].CIN);
}

int menu_input()
{
    int menu_item;
    scanf("%d",&menu_item);
    return menu_item;
}

void withdrawal()
{
    current_account_header();
    float withdraw = 0;
    printf("\nPlease enter an amount to withdraw: ");
    scanf("%f",&withdraw);

    if (accounts[current_bank_account].current_amount < withdraw)
    {
        printf("\nNo enough money.\n");
    }
    else
    {
        accounts[current_bank_account].current_amount -= withdraw;
        printf("\n\nWithdrawal successful!");
    }

}

void deposit()
{
    current_account_header();
    float deposit = 0;
    printf("\nPlease enter an amount to deposit: ");
    scanf("%f",&deposit);
    accounts[current_bank_account].current_amount += deposit;
    printf("\nDeposit was successful!");
}
void display_account_summary()
{
    current_account_header();
    printf("\n//________Account summary________//");
    printf("\nCIN: %s",accounts[current_bank_account].CIN);
    printf("\nFirst Name: %s",accounts[current_bank_account].first_name);
    printf("\nLast Name: %s", accounts[current_bank_account].last_name);
    printf("\nAmount: %.2f MAD",accounts[current_bank_account].current_amount);
}

void display()
{
    int choice;
    clear_screen();
    displayMenu();


    scanf("%d",&choice);

        switch(choice){

        case 1:
            normalDisplay();
            break;
        case 2:
            displayAsc();
            break;
        case 3:
            displayDesc();
            break;
}
}
void displayMenu()
{
    printf("\n//_______Account Menu_______//\n");
    printf("\n 1 - Display the accounts.\n");
    printf(" 2 - Display the accounts in ascending order.\n");
    printf(" 3 - Display the accounts in descending order.\n");
    printf(" 0 - Return to the main menu.\n");
    printf("\n//__________________________//\n");
    printf("State your choice:\n");

}
void normalDisplay()
{
    int choice;
    int i;
    if (bank_accounts_count == 0)
    {
        clear_screen();
        printf("There are no bank accounts found, Please add one first.");
        printf("\n 1 - Register a new account.");
        printf("\n 2 - Return to the main menu\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            creatingAcc();
        }

    }
     else
        {
            clear_screen();
            printf("//________%d Account(s) found.________//", bank_accounts_count);
            for(i=0;i<bank_accounts_count;i++)
            {
                printf("\n\nCIN: %s",accounts[i].CIN);
                printf("\nFirst name: %s",accounts[i].first_name);
                printf("\nLast name: %s",accounts[i].last_name);
                printf("\nAmount: %.2f MAD\n\n",accounts[i].current_amount);
            }
            printf("\n//____________________________________//\n\n\n");
        }

}

void displayAsc()
{
    int choice;
    int i, j;

    if (bank_accounts_count == 0)
    {
        clear_screen();
        printf("There are no bank accounts found, Please add one first.");
        printf("\n 1 - Register a new account.");
        printf("\n 2 - Return to the main menu\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            creatingAcc();
        }

    }
     else
        {
        clear_screen();
        for(i=0;i<bank_accounts_count;i++){
            for (j=0;j<bank_accounts_count-1;j++){
                if(accounts[j].current_amount > accounts[j+1].current_amount){
                    int temp = accounts[j].current_amount;
                    accounts[j].current_amount = accounts[j+1].current_amount;
                    accounts[j+1].current_amount = temp;
                }
            }
        }

        }
        for(i=0;i<bank_accounts_count;i++)
        {
            printf("\nCIN: %s",accounts[i].CIN);
            printf("\nFirst Name: %s",accounts[i].first_name);
            printf("\nLast Name: %s",accounts[i].last_name);
            printf("\nAmount: %.2f MAD\n\n",accounts[i].current_amount);
        }


}

void displayDesc()
{
    int choice;
    int i, j;
    if (bank_accounts_count == 0)
    {
        clear_screen();
        printf("There are no bank accounts found, Please add one first.");
        printf("\n 1 - Register a new account.");
        printf("\n 2 - Return to the main menu\n\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            creatingAcc();
        }

    }
     else
        {
            clear_screen();

            for(i=0;i<bank_accounts_count;i++)
            {
                for (j=0;j<bank_accounts_count-1;j++){
                    if(accounts[j].current_amount < accounts[j+1].current_amount){
                        int temp = accounts[j].current_amount;
                        accounts[j].current_amount = accounts[j+1].current_amount;
                        accounts[j+1].current_amount = temp;
                    }
                }
            }

        }
        for(i=0;i<bank_accounts_count;i++)
        {
            printf("\nCIN: %s",accounts[i].CIN);
            printf("\nFirst Name: %s",accounts[i].first_name);
            printf("\nLast Name: %s",accounts[i].last_name);
            printf("\nAmount: %.2f MAD\n\n",accounts[i].current_amount);
        }

}
void add_percent(){
    struct Bank_account temp_account;
    int i, j;
    if (bank_accounts_count == 0)
    {
        printf("\nThere are no bank accounts\n");


    }
    else
    {
        for (i=0; i<bank_accounts_count; i++)
        {
            for(j=0; j<bank_accounts_count-1; j++){
                if(accounts[j].current_amount<accounts[j+1].current_amount){
                    temp_account=accounts[j];
                    accounts[j]=accounts[j+1];
                    accounts[j+1]=temp_account;
                }
            }
        }
        for(i=0;(i<bank_accounts_count)&&(i<3);i++){
            accounts[i].current_amount *= 1.013;
            printf("\n Added 1.3% bonus!\n");
        }

    }
}

void clear_screen()
{

    system("cls");
}
