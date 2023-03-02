#include <stdio.h>

int calculate_products(long number);
long calculate_sum2(long number);
int calculate_lenght(long number);
long s_digits(long number);

int main(void)
{
    // prompt for input
    long number = printf("Number: ");
    scanf("%ld", &number);

    // calculate the checksum
    int sum1 = calculate_products(number);
    long sum2 = calculate_sum2(number);
    long checksum = sum1 + sum2;
    checksum %= 10;
    if (checksum != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // check for card lenght and starting digits
    int lenght = calculate_lenght(number);
    if (lenght != 13 && lenght != 15 && lenght != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    long starting_digits = s_digits(number);

    // print AMEX, MASTERCARD, VISA or INVALID
    if ((starting_digits == 34 && lenght == 15) || (starting_digits == 37 && lenght == 15))
    {
        printf("AMEX\n");
    }
    else if ((starting_digits < 56 && starting_digits > 50) && lenght == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((starting_digits == 4 && lenght == 13) || (starting_digits == 4 && lenght == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

int calculate_products(long number)
{
    int digit, product, last_digit, first_digit;
    int sum = 0;
    while (number > 9)
    {
        number /= 10;
        digit = number % 10;
        product = digit * 2;
        if (product > 9)
        {
            last_digit = product % 10;
            first_digit = product / 10;
            sum = sum + last_digit + first_digit;
        }
        else
        {
            sum = sum + product;
        }
        number /= 10;
    }
    return sum;
}
long calculate_sum2(long number)
{
    long sum = 0;
    while (number > 9)
    {
        int digit = number % 10;
        number /= 10;
        sum += digit;
        number /= 10;
    }
    sum = sum + number;
    return sum;
}
int calculate_lenght(long number)
{
    int lenght;
    for (lenght = 2; number > 99; lenght++)
    {
        number = number / 10;
    }
    return lenght;
}
long s_digits(long number)
{
    for (int i = 0; number > 99; i++)
    {
        number = number / 10;
    }
    if (number > 39 && number < 50)
    {
        number = number / 10;
    }
    return number;
}