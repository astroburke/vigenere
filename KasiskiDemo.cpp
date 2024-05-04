#include "Kasiski.h"

int main() {
    std::string ciphertext;

    std::cout << "Enter ciphertext: ";
    getline(std::cin, ciphertext);

    std::cout << std::endl;

    performKasiskiExamination(ciphertext);

    return 0;
}