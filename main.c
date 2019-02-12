/*
Author: Keegan Moore && TJ
C Program: Vending Machine
Date:04 April 2014

     GROUP PROJECT
This program will display a menu of a beverage selection.
In that selection, the operator
can fill the vending machine if they log in as admistrator.

The cost for each can is $1.75, the machine can only take $1 bills,
quarters, dimes and nickels.  It can only return
quarters, dimes and nickels.
*/

#include<stdio.h>
#include<stdlib.h>

#define bool int
#define true 1
#define false 0
#define COST 1.75       // we may need to make this a variable defined by admin

// Function Prototypes
int loginMenu();
int admin(int *d0, int *d1, int *d2, int *d3, int *d4, int *d5, int *d6, int *d7, int *d8, int *d9);    // add &d,q,d,n
int customer(int *d0, int *d1, int *d2, int *d3, int *d4, int *d5, int *d6, int *d7, int *d8, int *d9); // add &d,q,d,n, cost
int getChoices();
void getInv(int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9);
bool setInv(int *d0p, int d0, int *d1p, int d1, int *d2p, int d2, int *d3p, int d3, int *d4p, int d4,
            int *d5p, int d5, int *d6p, int d6, int *d7p, int d7, int *d8p, int d8, int *d9p, int d9);
bool setOne(int *dp, int d);
float Payment();
void returnFunds(float chDue);
bool takeOne(int *dp);
// Global Variable Dec
int main()
{  // control function
    int err = 0;
    int user = 0;
    int numOfNickels = 0;       // undetermined
    int numOfDimes = 0;         // ""
    int numOfQuarters = 0;      // ""
    int numOfDollars = 0;       // should not need extra dollars, user is limited to 95 cents change by Payment()
    float bank = ((numOfNickels * 0.05) + (numOfDimes * 0.10) + (numOfQuarters * 0.25) + numOfDollars);
    // 10 drinks: inventory starts at 1
    int initInv = 1;
    int d0 = initInv, d1 = initInv, d2 = initInv, d3 = initInv, d4 = initInv, d5 = initInv, d6 = initInv, d7 = initInv, d8 = initInv, d9 = initInv;

    if(!setInv(&d0, d0, &d1, d1, &d2, d2, &d3, d3, &d4, d4, &d5, d5, &d6, d6, &d7, d7, &d8, d8, &d9, d9))
        printf("Error while updating the inventory! Oops!\n");

    printf("Welcome to the C Vending Machine!\n");
    while(1)
    {
        printf("\n\n");
        user = loginMenu();  // Choose user - login menu returns -1 if error occurs
        if (user == 1)
        {
            err = admin(&d0, &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9);
            printf("Finished Administrator session with error code: %d\n", err);
        }
        else if (user == 2)
        {
            err = customer(&d0, &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9);
            printf("Finished Customer session with error code: %d\n", err);
            // could use error code to update bank?
            // 0 for no transaction?
            // 1 for transaction successful?
            // -1 for error in transaction?
        }
        else
            printf("User Invalid. Let's Try Again.\n");
    }
    return err;
}

int admin(int *d0, int *d1, int *d2, int *d3, int *d4, int *d5, int *d6, int *d7, int *d8, int *d9/*, float *b*/)
{  // Administrator session
    int err = 0;  // 0 good, -1 bad
    /*
    The administrator will first get a report about how many
    items are in the hoppers and can only refill to the maximum
    capcity for each drink of exactly 20 cans.
    The admistrator can choose to remove an existing inventory or reduce it.

    The administrator should be able to log out to put the machine
     in vending mode.  No purchases can be made
    while the machine is in administrative mode.
    */
    getInv(*d0, *d1, *d2, *d3, *d4, *d5, *d6, *d7, *d8, *d9);



    return err;
}
int customer(int *d0, int *d1, int *d2, int *d3, int *d4, int *d5, int *d6, int *d7, int *d8, int *d9/*, float *b*/)
{  // customer session
    /*
    If the operator logs in as a custormer then they have the
    opportunity to select a beverage, pay for the beverage
    and then the machine will dispense the beverage and change due.
    If a customer selects a beverage that is not stocked,
    the customer will get their money back with a message
    indicating that the item is out of stock.
    */
    int err = 0;  // 0 good, -1 bad
    int select = -1;
    float changeDue = 0.00;
    int inv[10] = {*d0, *d1, *d2, *d3, *d4, *d5, *d6, *d7, *d8, *d9};   // Content Ref
    int* invP[10] = {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9};           // Loc Ref (P for pointer)
    select = getChoices();
    if(select == 10)
    {
        printf("You have chosen to exit. Logging out of Customer now.\n");
        return 0;
    }
    else
    {
        printf("You have selected drink %d.\n", select);
        printf("The cost of your selection is %.2f\n", COST);
        /* **********************************************************************
        Get Money
        Check Stock
            Take out of Stock
        give change
        ********INVENTORY NOT UPDATING**************
        **FIX:
        Line 101: int inv[10]   ~ this array should hold the stock
        Line 102: int* invP[10] ~ this array holds the location, therefore needs *
                                ~ noted by P
        ************************************************************************ */
        changeDue = Payment();
        printf("The amount of money that you inserted is: $%.2f\n", changeDue);
        if(changeDue >= COST && (inv[select] > 0))  // enough money and inventory
        {
            takeOne(invP[select]);  // invP for Loc ref
            changeDue -= COST;
            returnFunds(changeDue);
            // *b += COST;
        }
        else
        {  // not enough in stock or not enough money
            if ( !(inv[select] > 0) )
            {

                printf("Sorry, that item is out of stock.\n");
            }

            returnFunds(changeDue);
        }
    }
    return 0;
}
void returnFunds(float chDue)
{
    //printf("This is the change due: %.2f\n", chDue);
    float total = chDue;
    //printf("total = %.2f\n", total);
    int qrtr = 0;
    int dime = 0;
    int nick = 0;
    while(chDue >= 0.25)
    {
        chDue -= 0.25;
        qrtr += 1;
    }
    //printf("Number of quarters: %d\n", qrtr);
    while(chDue >= 0.10)
    {
        chDue -= 0.10;
        dime += 1;
    }
    //printf("Number of dimes: %d\n", dime);
    while(chDue >= 0.05)
    {
        chDue -= 0.05;
        nick += 1;
    }
    //printf("Number of nickels: %d\n", nick);
    printf("You receive %d quarters, %d dimes, and %d nickels.\n", qrtr, dime, nick);
    printf("Your total change is %.2f\n", total);
}
float Payment()
{  // collects payments from Customer
    float deposit = 0.00;
    int choice = 0;
    while (deposit < COST) // Only accepts enough to pay for drink
    {
        printf("You have inserted $%.2f so far.\n", deposit);
        printf("Insert one dollar   ~ 1\n");
        printf("Insert one quarter  ~ 2\n");
        printf("Insert one dime     ~ 3\n");
        printf("Insert one nickel   ~ 4\n");
        printf("Stop transaction    ~ 9\n");
        printf("Choose deposit: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: deposit += 1.00; // deposit = deposit + 1.00
                    break;
            case 2: deposit += 0.25;
                    break;
            case 3: deposit += 0.10;
                    break;
            case 4: deposit += 0.05;
                    break;
            case 9: printf("Did not exit deposit as planned.\n");  // check if return successful
                    return deposit;
		    break;
            default:printf("Not a valid choice. Choose again.");   // in case of random other choice
                    break;
        }
    }
    return deposit;
}
bool setInv(int *d0p, int d0, int *d1p, int d1, int *d2p, int d2, int *d3p, int d3, int *d4p, int d4,
            int *d5p, int d5, int *d6p, int d6, int *d7p, int d7, int *d8p, int d8, int *d9p, int d9)
{  // changes all of the inv values
    bool valid = 1;
    if (d0 >= 0 && d0 <=20) *d0p = d0;
    else    valid = false;
    if (d1 >= 0 && d1 <=20) *d1p = d1;
    else    valid = false;
    if (d2 >= 0 && d2 <=20) *d2p = d2;
    else    valid = false;
    if (d3 >= 0 && d3 <=20) *d3p = d3;
    else    valid = false;
    if (d4 >= 0 && d4 <=20) *d4p = d4;
    else    valid = false;
    if (d5 >= 0 && d5 <=20) *d5p = d5;
    else    valid = false;
    if (d6 >= 0 && d6 <=20) *d6p = d6;
    else    valid = false;
    if (d7 >= 0 && d7 <=20) *d7p = d7;
    else    valid = false;
    if (d8 >= 0 && d8 <=20) *d8p = d8;
    else    valid = false;
    if (d9 >= 0 && d9 <=20) *d9p = d9;
    else    valid = false;
    return valid;
}
bool setOne(int *dp, int d)
{  // changes the inv one drink at a time
    bool valid = 1;
    if (d >= 0 && d <=20) *dp = d;
    else    valid = false;
    return valid;
}
bool takeOne(int *dp)
{  // takes one from inv
    bool valid = 1;
    //printf("valid = %d\n", valid);
    //printf("The contents of dp are %d\n", *dp);
    if (*dp > 0)
    {
        *dp= *dp - 1;
        printf("One drink removed from inventory.\n");
    }
    else
    {
        printf("Attempt to remove drink from inventory. Inventory not changed.\n");
        valid = false;
    }
    //printf("valid = %d\n", valid);
    //printf("The contents of dp are %d\n", *dp);
    return valid;
}
int getChoices()
{  // prints a nice display of the drinks to choose from
    int tries = 0;
    int choice = -1;
    printf("\n____________________________________\n");
    printf("| The C Vending Machine |   Price   |\n");
    printf("|-----------------------|-----------|\n");
    printf("|-----------------------|-----------|\n");
    printf("|   Pepsi ~~ Choice 0   |   $%.2f   |\n", COST);
    printf("|   Pepsi ~~ Choice 1   |   $%.2f   |\n", COST);
    printf("|   Pepsi ~~ Choice 2   |   $%.2f   |\n", COST);
    printf("|   Pepsi ~~ Choice 3   |   $%.2f   |\n", COST);
    printf("|   Pepsi ~~ Choice 4   |   $%.2f   |\n", COST);
    printf("|   Pepsi ~~ Choice 5   |   $%.2f   |\n", COST);
    printf("|   Pepsi ~~ Choice 6   |   $%.2f   |\n", COST);
    printf("|   Pepsi ~~ Choice 7   |   $%.2f   |\n", COST);
    printf("|   Pepsi ~~ Choice 8   |   $%.2f   |\n", COST);
    printf("|   Pepsi ~~ Choice 9   |   $%.2f   |\n", COST);
    printf("|-----------------------|-----------|\n");
    printf("|      EXIT   (10)      |-----------|\n");
    printf("|_______________________|___________|\n");
    printf("Please make a choice -> ");
    scanf("%d", &choice);	// should not scan first
    if(!(choice >= 0 && choice <= 10))
    {
        for(tries; tries < 5; tries+=1)
        {
            if(choice < 0 || choice > 10)
            {
                printf("Please choose again ->");
                scanf("%d", &choice);
            }
        }
    }
    return choice;
}
void getInv(int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9)
{  // prints a nice display of the inventory for administrator purposes
    //int err = 0;
    printf("\n____________________________________\n");
    printf("| The C Vending Machine | Inventory |\n");
    printf("|-----------------------|-----------|\n");
    printf("|-----------------------|-----------|\n");
    printf("|   Pepsi ~~ Choice 0   |    %d     |\n", d0);
    printf("|   Pepsi ~~ Choice 1   |    %d     |\n", d1);
    printf("|   Pepsi ~~ Choice 2   |    %d     |\n", d2);
    printf("|   Pepsi ~~ Choice 3   |    %d     |\n", d3);
    printf("|   Pepsi ~~ Choice 4   |    %d     |\n", d4);
    printf("|   Pepsi ~~ Choice 5   |    %d     |\n", d5);
    printf("|   Pepsi ~~ Choice 6   |    %d     |\n", d6);
    printf("|   Pepsi ~~ Choice 7   |    %d     |\n", d7);
    printf("|   Pepsi ~~ Choice 8   |    %d     |\n", d8);
    printf("|   Pepsi ~~ Choice 9   |    %d     |\n", d9);
    printf("|-----------------------|-----------|\n");
    printf("|      EXIT   (10)      |-----------|\n");
    printf("|_______________________|___________|\n");
    //printf("Edit inventory of a choice above -> "); // outside display?
    //return err;
}
int loginMenu()
{  // prints Login Menu
    int user = -1;
    printf("\tAdministrator:\t Enter 1\n");
    printf("\tCustomer:\t Enter 2\n");
    printf("Who are you? -> ");
    scanf("%d", &user);
    return user;
}
