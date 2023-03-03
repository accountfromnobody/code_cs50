#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user with a text
    string text = get_string("Text: ");

    // Count the number of letters
    int letters = count_letters(text);
    /*printf("%i letters\n", letters);*/

    // Count the number of words
    int words = count_words(text);
    /*printf("%i words\n", words);*/

    // Count the number of sentences
    int sent = count_sentences(text);
    /*printf("%i sentences\n", sent);*/

    // Putting it all together in the Coleman-Liau formula
    float L = (letters / (float) words) * 100;
    float S = (sent / (float) words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    /*printf("%f %f %.0f\n", L, S, index);*/

    // Print the grade level
    if (index >= 1 && index < 16)
    {
        printf("Grade %.0f\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == 32)
        {
            words += 1;
        }
    }
    words += 1;
    return words;
}

int count_sentences(string text)
{
    int sent = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sent += 1;
        }
    }
    return sent;
}