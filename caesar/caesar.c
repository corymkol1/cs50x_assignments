// Caesar

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
// Make sure exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// Make sure every character in the key is a digit
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// Convert the key from a string to an integer
    int key = atoi(argv[1]);

// Ask the user for plaintext
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

// Encrypt each character
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }

    printf("\n");

    return 0;
}

// Returns true only if every character in the string is a digit
bool only_digits(string s)
{
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }

    return true;
}

// Rotates an alphabetical character by key positions
char rotate(char c, int key)
{
// Reduce large keys to a value between 0 and 25
    key = key % 26;

    if (isupper(c))
    {
        return ((c - 'A' + key) % 26) + 'A';
    }
    else if (islower(c))
    {
        return ((c - 'a' + key) % 26) + 'a';
    }

// Leave spaces, punctuation, numbers, etc. unchanged
    return c;
}

// Cory M Kolvinsky
