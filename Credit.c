#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long num = get_long("Please give me a credit card number\n"); //user input
    long n = num;
    int len = 0;

    // Figures out how long number is
    while (n > 0)
    {
        n /= 10;
        len++;
    }

    long arr[len];
    len = 0;
    n = num;

    // Splits number into array (in reverse order)
    while (n > 0)
    {
        arr[len] = n % 10;
        n /= 10;
        len++;
    }

    // Variables for loops
    int total1 = 0;
    int total2 = 0;

    // Multiplies every other digit by 2 and adds them together, starting with the second last (second in array) digit
    for (int i = 1; i < len; i += 2)
    {
        int a = arr[i] * 2;
        if (a > 9) // Deals with 2 digit numbers
        {
            while (a > 0)
            {
                total1 += a % 10;
                a /= 10;
            }
        }
        else
        {
            total1 += a;
        }
    }

    // Adds remaining digits together
    for (int i = 0; i < len; i += 2)
    {
        total2 += arr[i];
    }

    // Adds both totals together
    int finalTotal = total1 + total2;

    // If/Else chain for result
    if (finalTotal % 10 == 0)
    {
        if ((len == 15) && (arr[len - 1] == 3) && (arr[len - 2] == 4 || arr[len - 2] == 7))
        {
            printf("AMEX\n");
        }
        else if ((len == 13 || len == 16) && (arr[len - 1] == 5) && (arr[len - 2] > 0 && arr[len - 2] < 6))
        {
            printf("MASTERCARD\n");
        }
        else if ((len == 16 || len == 13) && (arr[len - 1] == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
