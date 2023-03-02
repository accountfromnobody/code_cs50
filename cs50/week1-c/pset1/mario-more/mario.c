#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompting the user
    int height, row, column, space;
    do
    {
        printf("Height: ");
        scanf("%d", &height);
    }
    while (1 > height || height > 8);

    // new row
    for (row = 0; row < height; row++)
    {
        // left pyramid
        // new space
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        // new column
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        // 2 constant space bars
        printf("  ");
        // right pyramid
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}