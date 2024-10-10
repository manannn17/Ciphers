This project is subjected to copyrights and it belogngs to the University of Illinois at Chicago

# Ciphers

Readme:

description:
Task: Caesar Cipher Encoder
Description: This task involves implementing a Caesar cipher encoder, where each letter of the plaintext is shifted forward in the alphabet by a constant number specified by the user (the "key").
Subtask: String Utility Functions:
Implemented int findIndexInAlphabet(char c) to find the index of a character in the alphabet.
Implemented char rot(char c, int amount) to rotate a single character by a specified amount.
Implemented string rot(string line, int amount) to rotate each letter in a string by a specified amount.
Subtask: Encrypt with Caesar shift:
Prompt the user for input twice: once for the text to encrypt and once for the number of characters to rotate by.
Encrypt the input text using the Caesar cipher with the specified rotation amount.
Task: Vigenère Cipher Encoder
Description: This task involves implementing a Vigenère cipher encoder, where each letter of the plaintext is encoded with a different shift based on a provided "key".
Subtask: Encrypt with Vigenère Cipher
Prompt the user for input twice: once for the text to encrypt and once for the Vigenère key.
Encrypt the input text using the Vigenère cipher, where each letter is shifted by the corresponding letter in the key.
Convert plaintext letters to uppercase and remove non-alphabetic characters.
Convert the Vigenère key to uppercase and remove non-alphabetic characters.
