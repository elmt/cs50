#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int key = 0;

int main(int argc, string argv[])
{
    if ((argc == 2) && (argv[1] > 0))
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // Checks that key argument is all digits
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: %s key\n", argv[0]);
                return 1;
            }
        }

        key = atoi(argv[1]);
        // For dealing with keys larger than 26 (26 represents no shift)
        if (key > 26)
        {
            key %= 26;
        }
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Requests user input
    string plaintext = get_string("plaintext: \n");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Capital letters: 65 - 90
        // Lowercase letters: 97 - 122
        if ((plaintext[i] >= 65 && plaintext[i] <= 90) || (plaintext[i] >= 97 && plaintext[i] <= 122))
        {
            if ((plaintext[i] + key > 90 && plaintext[i] < 97) || (plaintext[i] + key > 122))
            {
                // For shifts that need to go around to the start of the alphabet
                printf("%c", plaintext[i] - (26 - key));
            }
            else
            {
                // For letter/key combos that don't shift beyond Z/z
                printf("%c", plaintext[i] + key);
            }
        }
        else
        {
            // Non-alphabetic characters
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
