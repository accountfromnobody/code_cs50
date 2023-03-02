#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string argv[1]);

int main(int argc, string argv[])
{
    int length = strlen(argv[1]);
    for (int k = 0; k < length; k++)
    {
        switch (argv[1][k])
        {
        case 'a': printf("6"); break;
        case 'e': printf("3"); break;
        case 'i': printf("1"); break;
        case 'o': printf("0"); break;
        default: printf("%c", argv[1][k]); break;
        }
    }
    printf("\n");
}