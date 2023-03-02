#include <stdio.h>

int main(void)
{
    int age = printf("What's your age? ");
    scanf("%i", &age);

    printf("Your age is %i!\n", age);
}