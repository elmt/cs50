#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);

int main(void)
{
    int height = get_height("Please give me a number between 1 and 8\n");
    for (int i = 0; i < height; i++)
    {
        // First half of pyramid
        for (int spaces = height - i; spaces > 1; spaces--)
        {
            printf(" ");
        }
        for (int hashes = 0; hashes < i + 1; hashes++)
        {
            printf("#");
        }
        // Space between pyramid halves
        printf("  ");
        // Second half
        for (int hashes = 0; hashes < i + 1; hashes++)
        {
            printf("#");
        }
        printf("\n");
    }


}

// Repeatedly prompt user if number not between 1 and 8
int get_height(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}
