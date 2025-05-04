#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0, j, count[50] = {0};
    char str[50];
    
    printf("Enter the string: ");
    scanf("%s", str);  // %s reads a string

    printf("\n\tOriginal String is: %s", str);
    printf("\n\n\tEncoded String is: ");

    int l = strlen(str);

    while(i < l)
    {
        count[i] = 1; // Each character appears at least once
        j = i + 1;

        while (str[i] == str[j])  // Check how many times the same char repeats
        {
            count[i]++;
            j++;
        }

        printf("%c%d", str[i], count[i]);  // Print character and its count

        i = j;  // Move to the next different character
    }

    return 0;
}
