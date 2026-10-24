#include <ctype.h>
#include <stdio.h>

int main(void)
{
    long letters = 0;
    long words = 0;
    long sentences = 0;
    int in_word = 0;
    int c;

    printf("Text: ");
    fflush(stdout);

    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (isalpha(c))
        {
            letters++;
        }

        if (isspace(c))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            words++;
            in_word = 1;
        }

        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    if (words == 0)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    //letters and sentences per 100 words.
    double L = 100.0 * letters / words;
    double S = 100.0 * sentences / words;
    double index = 0.0588 * L - 0.296 * S - 15.8;

    // Apply the limits after rounding to the nearest integer.
    if (index < 0.5)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 15.5)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) (index + 0.5));
    }

    return 0;
}
