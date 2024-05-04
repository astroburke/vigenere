#include <cassert>

#include "Vigenere.h"
#include "Kasiski.h"

int main() {
    // Example from wikipedia
    std::string plaintext = "ATTACKATDAWN";
    std::string key = "LEMON";

    std::string ciphertext = encryptVigenere(plaintext, key);
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    std::string decryptedtext = decryptVigenere(ciphertext, key);
    std::cout << "Decrypted Text: " << decryptedtext << std::endl;

    assert(plaintext == decryptedtext);

    // Example from https://pages.mtu.edu/~shene/NSF-4/Tutorial/VIG/Vig-Kasiski.html
    std::string plaintext2 = "LFWKIMJCLPSISWKHJOGLKMVGURAGKMKMXMAMJCVXWUYLGGIISWALXAEYCXMFKMKBQBDCLAEFLFWKIMJCGUZUGSKECZGBWYMOACFVMQKYFWXTWMLAIDOYQBWFGKSDIULQGVSYHJAVEFWBLAEFLFWKIMJCFHSNNGGNWPWDAVMQFAAXWFZCXBVELKWMLAVGKYEDEMJXHUXDAVYXL";

    performKasiskiExamination(plaintext2);                                   
}