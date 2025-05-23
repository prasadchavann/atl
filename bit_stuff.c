// Algorithms
//  Start
//  Initialize the array for transmitted stream with the special bit
// pattern 01111110 which indicates the beginning of frame
//  Get the bit stream to be transmitted into the array
//  Check for five consecutive ones if they occur, stuff a bit 0.
//  Display the data transmitted as it appears on the data line after
// appending 01111110
//  For de-stuffing, copy the transited data to another array after
// detecting the stuffed bits.
//  Display the received bit stream
//  Stop

#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

int main() {
    char in[MAXSIZE];
    char stuff[MAXSIZE];
    char destuff[MAXSIZE];

    int i = 0, j = 0, count = 0;

    printf("Enter the input binary string (0's and 1's only):\n");
    scanf("%s", in);

    // BIT STUFFING
    while (in[i] != '\0') {
        stuff[j] = in[i];

        if (in[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        if (count == 5) {
            j++;
            stuff[j] = '0';  // Stuffing 0 after five 1's
            count = 0;
        }

        i++;
        j++;
    }
    stuff[j] = '\0';

    printf("\nThe stuffed character string is:\n%s\n", stuff);

    // BIT DESTUFFING
    i = 0;
    j = 0;
    count = 0;

    while (stuff[i] != '\0') {
        destuff[j] = stuff[i];

        if (stuff[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        if (count == 5) {
            i++; // skip the stuffed 0
            count = 0;
        }

        i++;
        j++;
    }
    destuff[j] = '\0';

    printf("\nThe destuffed character string is:\n%s\n", destuff);

    return 0;
}
