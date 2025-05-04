// 1) Insert Simple message and key (Both should have same length)
// 2) Perform XOR of message and key
// 3) Result is the Cipher Text (Encrypted message)
// 4) Perform XOR of Result and key
// 5) Output will be the original message.

#include <stdio.h>
#include <string.h>

int main() {
    char Msg[100] = "HELLO";  // Original message
    char Key = 'K';           // Encryption key (single character)
    char CTxt[100];           // Encrypted message
    char DTxt[100];           // Decrypted message
    int i;

    // Encryption using XOR
    for (i = 0; i < strlen(Msg); i++) {
        CTxt[i] = Msg[i] ^ Key;  // XOR each character with the key
    }
    CTxt[i] = '\0'; // Null-terminate the encrypted string

    printf("Encryption and Decryption using XOR Cryptography\n");
    printf("Original Message is: %s\n", Msg);
    printf("Encrypted Message is: ");

    for (i = 0; i < strlen(CTxt); i++) {
        printf("%c", CTxt[i]); // This may print non-printable characters
    }
    printf("\n");

    // Decryption using XOR (same key)
    for (i = 0; i < strlen(CTxt); i++) {
        DTxt[i] = CTxt[i] ^ Key;
    }
    DTxt[i] = '\0'; // Null-terminate the decrypted string

    printf("Decrypted Message is: %s\n", DTxt);

    return 0;
}
