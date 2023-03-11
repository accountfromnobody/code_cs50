#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO

    // Base case
    if (input[0] == '\0')
    {
        return 0;
    }
    // Convert char into its numeric value
    int num = (input[strlen(input) - 1] - '0');

    // Remove the last char from the string by moving '\0' one position to the left
    input[strlen(input) - 1] = '\0';

    // Return this value plus 10 times the integer value of the new shortened string
    return num + 10 * convert(input);
}