/*Vending_Machine.c
Author: 
Date:
     GROUP PROJECT
     
     
This program will display a menu of a beverage selection.  
In that selection, the operator
can fill the vending machine if they log in as admistrator.

If the operator logs in as a custormer then they have the opportunity to select a beverage, 
pay for the beverage and then the machine will dispense the beverage and change due.

If a customer selects a beverage that is not stocked, 
the customer will get their money back with a message
indicating that the item is out of stock.

The administrator will first get a report about how many items are in the hoppers
 and can only refill to the maximum capcity for each drink of exactly 20 cans.  

The admistrator can choose to remove an existing inventory or reduce it.
The cost for each can is $1.75, the machine can only take $1 bills, quarters, dimes and nickels.  
It can only return quarters, dimes and nickels.

The administrator should be able to log out to put the machine in vending mode.
No purchases can be made while the machine is in administrative mode.

*/

#include<stdio.h>

void menu(); //prototypes
void admin();
void option(int choice);
int inv[6] = {0, 20, 20, 20, 20, 20}; 


int main()
{
	//int fromMenu = 0;
	//int drink1 = 20;
	while(1)
	{
		//printf("%d\n", fromMenu);
		menu();
		//menu(&drink1);
		//printf("%d\n", fromMenu);
	}
	system("PAUSE");
	return 0;
} 

void menu()
//int *d1
{
	int choice = 0;
	int times = 0;
	//Display Menu
	printf("\n---Main Menu---\n");
	printf("Please choose beverage or log in as Admin\n\n");
	printf("1.\t Coke\n");
	printf("2.\t Diet Coke\n");
	printf("3.\t Cherry Coke\n");
	printf("4.\t Sprite\n");
	printf("5.\t Dr. Pepper\n");
	printf("6.\t Enter Admin Password\n\n");
	
	
	do
	{
		//Do code
		if (times == 0)
		{
			printf("Select Option: ");
			times++;
		}
		else if (times < 5)
		{
			printf("Invalid Option, Must be 1 through 6");
			times++;
		}	
		else 
		{
			printf("FAIL! Try againg later");
			break;
		}	
		scanf("%d", &choice);
		
	}while(choice < 1 || choice > 6);
	
	//switch statement
	switch(choice) 
	{
		case 6: printf("\nYou entered choice admin \n");
			admin(); 
			break;
		case 1: printf("\nYou have chosen Coca-Cola: $1.75\n");
			option(choice);
			break;
		case 2: printf("\nYou have chosen Diet Coke: $1.75\n");
			option(choice);
			break;
		case 3: printf("\nYou have chosen Cherry Coke: $1.75\n");
			option(choice);
			break;
		case 4: printf("\nYou have chosen Sprite: $1.75\n");
			option(choice);
			break;
		case 5: printf("\nYou have chosen Dr. Pepper: $1.75\n");
			option(choice);
			break;
		default:printf("---Fail---");
			break;
	}
		
}

void admin()//fuunction for admin session
{
	int x = 0;
	printf("\n---Admin session---\n");
	printf("Enter password:  ");
	
	//printf("\nPlease enter your password: \n");
	char Password[] = "admin";
	scanf("%s", &Password);
	
	//declare admin variable
	int ac;
	//if statement  for password 
	if (strcmp("admin", Password) ==0)
    {
     	printf("\n\tWelcome!\n");
     	//Display drink inventory
     	printf("\nMoney:\n");
     	printf("---------------------\n");
     	printf("--Product Inventory--\n");
     	printf("---------------------\n");
    	printf("Coke:\t\t%d\n", inv[1]);
		printf("Diet Coke:\t%d\n", inv[2]);
		printf("Cherry Coke:\t%d\n", inv[3]);
		printf("Sprite:\t\t%d\n", inv[4]);
		printf("Dr. Pepper:\t%d\n", inv[5]);
		printf("---------------------\n");
		printf("---------------------\n");
		printf("Add/Subtract Product:\t1\n");
		printf("Add/Subtract Money:  \t2\n");
		printf("Exit: \t\t\t0\n\t\t\t");
		//request admin choice
		scanf("%d", &ac);
		printf("%d\n", ac);
		//if statement for inventories
		if (ac == 0)
		{
			printf("Return to menu\n");
			menu();
		}
		else if (ac == 1)//drink inventory
		{
			int p;
			int number;
			printf("Choose Product to Add/Subtract:\t\n");
			printf("----------------------------\n");
			printf("1.\tCoke:\t\t%d\n", inv[1]);
			printf("2.\tDiet Coke:\t%d\n", inv[2]);
			printf("3.\tCherry Coke:\t%d\n", inv[3]);
			printf("4.\tSprite:\t\t%d\n", inv[4]);
			printf("5.\tDr. Pepper:\t%d\n", inv[5]);
			printf("0.\tCancel\n");
			
			scanf("%d", &p);
			if (p == 0)
			{
				printf("Return to menu\n");
				menu();
			}
			else
			{
			printf("Add/Subtract in option #:%d\n", p);
			printf("Enter number of drinks to add (use '-number' to subtract):");
			scanf("%d", &number);
			
			inv[p] = inv[p] + number;
			
			if (inv[p] < 0)//Constrain inventory limits
			{
				printf("\nExceeds negative limit!\n");
				inv[p] = inv[p] - number; 
			}
			else if (inv[p] > 20)
			{
				printf("\nExceeds limit!\n");
				inv[p] = inv[p] - number;
			}
			else//display inventory after change
			printf("----------------------\n");
			printf("--Product Inventory--\n");
     		printf("---------------------\n");
    		printf("Coke:\t\t%d\n", inv[1]);
			printf("Diet Coke:\t%d\n", inv[2]);
			printf("Cherry Coke:\t%d\n", inv[3]);
			printf("Sprite:\t\t%d\n", inv[4]);
			printf("Dr. Pepper:\t%d\n", inv[5]);
			printf("---------------------\n\n");
			}
				
		}
		else if (ac == 2)//money inventory
		{
			int m;
			printf("To add money, press \t'1'\n");//money inventory menu
			printf("To subtract money, press '2'\n");
			scanf("%d", &m);
			if (m == 1)
			{
				printf("\nAdd\n");
			}	
			else if (m == 2)
			{
				printf("\nSubtract\n");
			}
			else if (m == 0)
			{
				printf("Return to menu\n");
				menu();
			}
			else
			{
				printf("\nInvalid entry\n");
			}
			
			
		}
		else
		{
			printf("Invalid Option, Must be 0 through 2");
		}

     	
    }
	else
	{
	 	printf("\nThe password you entered is invalid.\n");
    }
	
	
}

void option(int choice)//selection subtracts from inventory
{
	if (inv[choice] <= 0)
	{
		printf("\nMake another selection!\n\n");
	}
	else 
	{
		inv[choice] = inv[choice] --;
	}		 
}

