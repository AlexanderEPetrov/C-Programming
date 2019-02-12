//charcompare_alex.c

#include<stdio.h>
void fflushstdin( void )
{
    int c;
    while( (c = fgetc( stdin )) != EOF && c != '\n' );
}
/* above function from: http://stackoverflow.com/questions/9562218/
c-mutliple-scanfs-when-i-enter-in-a-value-for-one-scanf-it-skips-the-second-s
*/

int main()
{
    char word[2];
    char *ptr;
    ptr = &word[0];
    
    //write to the array
    printf("Enter a letter: ");
    *ptr = getchar(); //use this instead of scanf()
    fflushstdin(); //flush the buffer
    ptr++; //move the pointer forward
    printf("Enter the next letter: ");
    *ptr = getchar();
    fflushstdin();
    
    ptr = &word[0]; //reset the pointer
    
    //read from the arrays
    printf("\nFirst letter: %c\n", *ptr);
    ptr++;
    printf("Second letter: %c\n", *ptr);
    //The above function is from example: Array02ptr
    
    if(word[0] == word[1])
    {
		printf("\nThe two characters are equal\n");
    }
    else
    {
		printf("\nThe two characters are not the same\n");
    }
    //The above if statement is from example: conditionaV2.c
    
    system("PAUSE");
    return 0;
}
