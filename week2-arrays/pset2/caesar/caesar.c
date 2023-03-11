#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string argv[]);
char rotate(char p, int k);

int main(int argc, string argv[])
{
    // The program only accepts a single command-line argument and a non-negative integer
    if (argc == 2 && only_digits(argv))
    {
        // convert the argv[1] string into an int
        int k = atoi(argv[1]);

        // prompt the user for input
        string plaintext = get_string("plaintext: ");

        // print the ciphertext
        printf("ciphertext: ");
        for (int i = 0, length = strlen(plaintext); i < length; i++)
        {
            // rotate a letter by k positions
            char c = rotate(plaintext[i], k);
            printf("%c", c);
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool only_digits(string argv[])
{
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char p, int k)
{
    char c;
    if (isupper(p))
    {
        p -= 'A';
        c = (p + k) % 26 + 'A';
        return c;
    }
    else if (islower(p))
    {
        p -= 'a';
        c = (p + k) % 26 + 'a';
        return c;
    }
    else
    {
        return p;
    }
}