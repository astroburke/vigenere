#include "../Vigenere.h"

/// Simple program that demonstrates Vigenere functions.

int main()
{
    std::string plaintext, key, ciphertext, decryptedtext;

    /// getline is used because we are expecting plaintext that may have whitespace
    std::cout << "Enter plaintext, use all caps and no punctuation: ";
    getline(std::cin, plaintext);

    std::cout << "Enter key, use all caps: ";
    getline(std::cin, key);

    ciphertext = encryptVigenere(plaintext, key);
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    decryptedtext = decryptVigenere(ciphertext, key);
    std::cout << "Decrypted Text: " << decryptedtext << std::endl;
}
