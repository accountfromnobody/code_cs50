#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("What's your age? ");
    string phonenumber = get_string("What's your phone number? ");

    printf("Name is %s\n" "Age is %i.\n" "Phone number is %s.\n", name, age, phonenumber);
}