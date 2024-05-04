#include "Kasiski.h"

int main() {
    std::string ciphertext;

    std::cout << "Enter ciphertext, all caps with no punctuation or white space: ";
    getline(std::cin, ciphertext);

    std::cout << std::endl;

    performKasiskiExamination(ciphertext);
}
