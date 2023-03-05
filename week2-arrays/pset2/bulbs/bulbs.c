#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    int bit[BITS_IN_BYTE];

    string message = get_string("Message: ");

    for (int i = 0, length = strlen(message); i < length; i++)
    {
        int decimal = message[i];

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            int sum = decimal % 2;

            if (sum != 0)
            {
                bit[j] = 1;
            }
            else if (sum == 0)
            {
                bit[j] = 0;
            }
            decimal /= 2;
        }
        for (int k = 7; k >= 0; k--)
        {
            print_bulb(bit[k]);
        }
        printf("\n");
    }
}
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}