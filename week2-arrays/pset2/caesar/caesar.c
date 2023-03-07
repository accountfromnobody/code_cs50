#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string argv[1]);
char rotate(char p, int k);

int main(int argc, string argv[])
{
    // The program only accepts a single command-line argument and a non-negative integer
    if (argc != 2 || argv[1][0] == 45)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (only_digits(argv) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert string into an integer
    int k = atoi(argv[1]);

    // prompt the user for input
    string plain = get_string("plaintext: ");

    // print the ciphertext
    printf("ciphertext: ");
    for (int i = 0, length = strlen(plain); i < length; i++)
    {
        // convert ASCII to alphabetical index
        // then using the formula
        char c = rotate(plain[i], k);

        // convert result back to ASCII
        if (isupper(plain[i]))
        {
            c += 65;
        }
        else if (islower(plain[i]))
        {
            c += 97;
        }
        printf("%c", c);
    }
    printf("\n");
}

bool only_digits(string argv[1])
{
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (isdigit(argv[1][i]) == 0)
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
        p -= 65;
        c = (p + k) % 26;
        return c;
    }
    else if (islower(p))
    {
        p -= 97;
        c = (p + k) % 26;
        return c;
    }
    else if (isalpha(p) == 0)
    {
        return p;
    }
    return 1;
}