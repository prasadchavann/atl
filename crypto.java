// 1) Insert Simple message and key (Both should have same length)
// 2) Perform XOR of message and key
// 3) Result is the Cipher Text (Encrypted message)
// 4) Perform XOR of Result and key
// 5) Output will be the original message.

import java.io.*;
import java.lang.String;

public class Xor4 {
    public static void main(String args[]) {
        String Msg = "HELLO";
        char Key = 'K';
        String CTxt = "";
        String DTxt = "";
        int xor, xor1;
        char temp, temp1;

        for(int i = 0; i < Msg.length(); i++) {
            xor = Msg.charAt(i) ^ Key;
            temp = (char) xor;
            CTxt = CTxt + temp;
        }

        System.out.println("Encryption and Decryption using XOR Cryptography");
        System.out.println("Original Message is: " + Msg);
        System.out.println("Encrypted Message is: " + CTxt);

        for(int i = 0; i < CTxt.length(); i++) {
            xor1 = CTxt.charAt(i) ^ Key;
            temp1 = (char) xor1;
            DTxt = DTxt + temp1;
        }

        System.out.println("Decrypted Message is: " + DTxt);
    }
}
