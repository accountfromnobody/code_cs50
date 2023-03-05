#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks]; // 2 times int hours = int hours[0] and int hours[1]

    for (int i = 0; i < weeks; i++) // 1. "Week '0' HW Hours: hours[0]" 2. "Week '1' HW Hours: hours[1]" BUT 2 Weeks!
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    float total = 0;
    float average = 0;

    if (output == 'T')
    {
        for (int i = 0; i < weeks; i++)
        {
            total += hours[i];
        }
        return total;
    }
    else if (output == 'A')
    {
        for (int i = 0; i < weeks; i++)
        {
            average += hours[i];
        }
        average /= weeks;
        return average;
    }
    return 0;
}