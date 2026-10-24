#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");

    long temp = number;
    int digits = 0;
    int first_digit = 0;
    int first_two_digits = 0;

    // Count digits
    while (temp > 0)
    {
        temp /= 10;
        digits++;
    }

    // Get first digit and first two digits
    temp = number;

    while (temp >= 100)
    {
        temp /= 10;
    }

    first_two_digits = temp;
    first_digit = first_two_digits / 10;

    // Luhn's Algorithm
    int sum = 0;
    int position = 0;
    temp = number;

    while (temp > 0)
    {
        int digit = temp % 10;

        if (position % 2 == 1)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit = (digit / 10) + (digit % 10);
            }
        }

        sum += digit;
        position++;
        temp /= 10;
    }

    // If checksum fails, card not valid
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // American Express:
    // 15 digits and starts with 34 or 37
    if (digits == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }

    // MasterCard:
    // 16 digits and starts with 51 through 55
    else if (digits == 16 && first_two_digits >= 51 && first_two_digits <= 55)
    {
        printf("MASTERCARD\n");
    }

    // Visa:
    // 13 or 16 digits and starts with 4
    else if ((digits == 13 || digits == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
// Cory M Kolvinsky
