// 1. Choose two prime numbers p and q and keep them secret
// 2. Calculate n=p*q
// 3. Calculate f(n)=(p-1)*(q-1)
// 4. Select e such that e is relatively prime to f(n)
// 5. Determine d such that (d)*(e) = 1 mod f (n) and that d< f (n)
// 6. Public key is {e, n} and Private key is {d, n}
// 7. Cipher Text = (Pain Text)e mod n
// 8. Pain Text = (Cipher Text)d mod n

#include <stdio.h>
#include <math.h>

int main()
{
    int p, q, n, phi, d, e, i, CT, PT;
    printf("\nEnter First Prime no: ");
    scanf("%d", &p);

    printf("\nEnter Second Prime no: ");
    scanf("%d", &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("\nChoose e such that it is relatively prime to %d: ", phi);
    scanf("%d", &e);

    // Find d such that (d * e) % phi == 1 (modular multiplicative inverse of e mod phi)
    for (d = 1; d < phi; d++)
    {
        if (((d * e) % phi) == 1)
            break;
    }

    printf("\nEnter the plain text number (numeric only): ");
    scanf("%d", &PT);  // PT is the plaintext (must be < n)

    // Encryption: CT = (PT^e) % n
    CT = 1;
    for (i = 0; i < e; i++)
        CT = (CT * PT) % n;

    printf("\nAfter Encryption (Cipher Text): %d", CT);

    // Decryption: PT = (CT^d) % n
    PT = 1;
    for (j = 0; j < d; j++)
        PT = (PT * CT) % n;

    printf("\nAfter Decryption (Original Plain Text): %d\n", PT);

    return 0;
}
