#include <stdio.h>

int main()
{
    float money;

    int choice;

    float change;

 

    printf("Name list of beverage: ");

    printf("\n\n");

    printf("1. Pepsi");                          printf("\t\t\tRM1.00\n");

    printf("2. Miranda");                        printf("\t\t\tRM1.00\n");

    printf("3. Mountain Dew");                   printf("\t\t\tRM1.00\n");

    printf("4. Coca Cola");                      printf("\t\t\tRM1.00\n");

    printf("5. Revive");                         printf("\t\t\tRM1.00\n");

    printf("6. Nestle Milo");                    printf("\t\t\tRM2.00\n");

    printf("7. Cincau");                         printf("\t\t\tRM1.00\n");

    printf("8. Chrysanthemum Tea");              printf("\t\tRM1.00\n");

    printf("9. Lipton Ice Lemon Tea");           printf("\t\tRM1.00\n");

    printf("10. Mineral Water");                  printf("\t\tRM1.00\n");

    printf("11. Cadburry Black Forest");          printf("\tRM3.60\n");

    printf("12. Kitkat");                         printf("\t\t\tRM2.00\n");

    printf("13. Crispy");                         printf("\t\t\tRM2.00\n");

    printf("14. Crunch");                         printf("\t\t\tRM2.50\n");

    printf("15. Mars");                           printf("\t\t\tRM2.50\n");

    printf("16. Kinder Bueno");                   printf("\t\tRM2.50\n");

    printf("17. White Kinder Bueno");             printf("\t\tRM2.50\n");

    printf("18. Milky Bar");                      printf("\t\t\tRM2.00\n");

    printf("19. M&M");                            printf("\t\t\t\tRM2.50\n");

    printf("20. Choki Choki");                    printf("\t\t\tRM2.00\n");

    printf("\n\n");

 

    printf("Enter your choice: ");

    scanf("%d",&choice);

 

    switch(choice)  {

    case 1:
		printf("You choose Pepsi");                  printf("\tRM1.00\n");
		break;

    case 2:
		printf("You choose Miranda");                printf("\tRM1.00\n");
		break;

    case 3:
		printf("You choose Mountain Dew");           printf("\tRM1.00\n");
		break;

    case 4:
		printf("You choose Coca Cola");              printf("\tRM1.00\n");
		break;

    case 5:
		printf("You choose Revive");                 printf("\tRM1.00\n");
		break;

    case 6:
		printf("You choose Nestle Milo");            printf("\tRM2.00\n");
		break;

    case 7:
        printf("You choose Cincau");                 printf("\tRM1.00\n");
		break;

    case 8:
		printf("You choose Chrysanthemum Tea");      printf("\tRM1.00\n");
		break;

    case 9:
		printf("You choose Lipton Ice Lemon Tea");   printf("\tRM1.00\n");
		break;

    case 10:
		printf("You choose Mineral Water");          printf("\tRM1.00\n");
		break;

    case 11:
		printf("You choose Cadburry Black Forest");  printf("\tRM3.60\n");
		break;

    case 12:
		printf("You choose Kitkat");                 printf("\tRM2.00\n");
		break;

    case 13:
		printf("You choose Crispy");                 printf("\tRM2.00\n");
		break;

    case 14:
		printf("You choose Crunch");                 printf("\tRM2.50\n");
		break;

    case 15:
		printf("You choose Mars");                   printf("\tRM2.50\n");
		break;

    case 16:
		printf("You choose Kinder Bueno");           printf("\tRM2.50\n");
		break;

    case 17:
		printf("You choose White Kinder Bueno");     printf("\tRM2.50\n");
		break;

    case 18:
		printf("You choose Milky Bar");              printf("\tRM2.00\n");
		break;

    case 19:
		printf("You choose M&M");                    printf("\tRM2.50\n");
		break;

    case 20:
		printf("You choose Choki Choki");            printf("\tRM2.00\n");
		break;

    default:
		printf("Invalid input!\n");
		break;

    }


    printf("Enter your money: ");

    scanf("%.2f",&money);

    printf("\n\n");

 

    if (money > 0)
		printf("ACCEPTED!\n");

    else
		printf("NOT ACCEPTED!\n");

    printf("\n\n");

 

    change = money - choice;

    printf("Your change is %.2f", change);

 

    return 0;

}
