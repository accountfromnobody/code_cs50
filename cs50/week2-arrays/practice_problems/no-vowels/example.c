// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string argv[1]);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string converted_word = replace(argv[1])
        printf("%s\n", converted_word);
    }
    else
    {
        printf("ERROR, please try again!\n");
        return 1;
    }
}

for (int k = 0; k < 5 ; k++)
{
    int n = argv[1][k];
    if (char == 'a' || char == 'A')
    {
        int n = 1;
        switch (n)
        {
            case 1:
                printf("6");
                break;
        }
    else if (char == 'e' || char == 'E')
    {
        int n = 2;
        case 2:
            printf("3");
            break;
    }
    else if (char == 'i' || char == 'I')
    {
        int n = 3;
        case 3:
            printf("1");
            break;
    }
    else if (char == 'o' || char == 'O')
    {
        int n = 4
        case 4:
            printf("0");
            break;
    }
    return
    }
    }



    /*if (argc == 2)
    {
        printf("%c\n", argv[1][0]);
    }
    else
    {
        printf("ERROR, please try again!\n");
        return 1;
    }*/