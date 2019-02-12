//trick_or_treat.c
#include<stdio.h>

int main()
{
    //data declaration
    int num_of_homes = 0;
    int num_of_candy = 0;
    int bag = 0;
    float average_take;
    int decision;
    //data input
    printf("Do you want to trick and treat?(1:y/2: n): ");
    scanf("%d", &decision);
    
    while(decision == 1)
    {
        printf("Enter the number of candies from house %d: ", num_of_homes + 1);
        scanf("%d", &num_of_candy);
        num_of_homes = num_of_homes + 1;
        bag = bag + num_of_candy;
        
        printf("Do you want to go to another house?(1: y/2: n): ");
        scanf("%d", &decision);
    }
    
    //data processing
    if (num_of_homes != 0)
    {
       average_take = bag /num_of_homes;
       //data output
       printf("The average take = %.2f\n", average_take);
       printf("You hit this many homes: %d\n", num_of_homes);
       printf("You collected a total of %d candies\n", bag);
    }
    
    
    system("PAUSE");
    return 0;
}
