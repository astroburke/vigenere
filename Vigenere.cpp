#include <iostream>
#include <string>
#include <array>

///
/// @brief Program that encrypts and decrypts plaintext using the Vigenere Cipher. Only accepts capital letters.
///
/// We set up a vigeneresquare. The encrypt function takes the plaintext and key
/// and refers to the vigeneresquare to correctly shift each character by the amount of
/// spaces dictated by the key. The decrypt function does the reverse. Main is the basic
/// implementation of these functions. Note that it only accepts capital letters.
///

///
/// Viginere square is an array of 26 strings, starting with the alphabet A-Z, then
/// rolling the string by 1 every subsequent string until all 26 possible key values are
/// filled up.
///
std::array<std::string, 26> vigeneresquare = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "BCDEFGHIJKLMNOPQRSTUVWXYZA",
    "CDEFGHIJKLMNOPQRSTUVWXYZAB",
    "DEFGHIJKLMNOPQRSTUVWXYZABC",
    "EFGHIJKLMNOPQRSTUVWXYZABCD",
    "FGHIJKLMNOPQRSTUVWXYZABCDE",
    "GHIJKLMNOPQRSTUVWXYZABCDEF",
    "HIJKLMNOPQRSTUVWXYZABCDEFG",
    "IJKLMNOPQRSTUVWXYZABCDEFGH",
    "JKLMNOPQRSTUVWXYZABCDEFGHI",
    "KLMNOPQRSTUVWXYZABCDEFGHIJ",
    "LMNOPQRSTUVWXYZABCDEFGHIJK",
    "MNOPQRSTUVWXYZABCDEFGHIJKL",
    "NOPQRSTUVWXYZABCDEFGHIJKLM",
    "OPQRSTUVWXYZABCDEFGHIJKLMN",
    "PQRSTUVWXYZABCDEFGHIJKLMNO",
    "QRSTUVWXYZABCDEFGHIJKLMNOP",
    "RSTUVWXYZABCDEFGHIJKLMNOPQ",
    "STUVWXYZABCDEFGHIJKLMNOPQR",
    "TUVWXYZABCDEFGHIJKLMNOPQRS",
    "UVWXYZABCDEFGHIJKLMNOPQRST",
    "VWXYZABCDEFGHIJKLMNOPQRSTU",
    "WXYZABCDEFGHIJKLMNOPQRSTUV",
    "XYZABCDEFGHIJKLMNOPQRSTUVW",
    "YZABCDEFGHIJKLMNOPQRSTUVWX",
    "ZABCDEFGHIJKLMNOPQRSTUVWXY"};

///
/// encryptVigenere takes plaintext and a key and outputs the encrypted message.
///
std::string encryptVigenere(const std::string &plaintext, const std::string &key)
{
    std::string ciphertext;
    int keyLength = key.length();

    /// Loop over entire plaintext string
    for (size_t i = 0, j = 0; i < plaintext.length(); i++)
    {
        /// check if char is alphabetic (e.g. want to skip over spaces)
        if (isalpha(plaintext[i]))
        {
            /// key[j % keyLength] effectively loops key when plaintext is longer than key.
            /// key[j % keyLength] - 'A' is an integer. While we could use ASCII reference values
            ///     it is easier to just do everything with respect to 'A'.
            /// vigeneresquare[][] takes the correct char from the correct string (in accordance
            ///     with the vigenere cipher rules) and returns our shifted char.
            /// We append it to ciphertext and increment j.
            char shift = vigeneresquare[key[j % keyLength] - 'A'][plaintext[i] - 'A'];
            ciphertext += shift;
            j++;
        }
        else
        {   
            /// j is not incremented since we don't want to progress the j counter when it's just spaces.
            ciphertext += plaintext[i];
        }
    }

    return ciphertext;
}

///
/// decryptVigenere takes ciphertext and a key and outputs the decrypted message.
///
std::string decryptVigenere(const std::string &ciphertext, const std::string &key)
{
    std::string plaintext;
    int keyLength = key.length();
    
    /// similar to encryptVigenere
    for (size_t i = 0, j = 0; i < ciphertext.length(); i++)
    {
        if (isalpha(ciphertext[i]))
        {
            /// instead of obtaining the encryption shift amount, we obtain decryption shift amount
            /// it is just the reverse process.
            char shift = (vigeneresquare[0][ciphertext[i] - 'A'] - vigeneresquare[key[j % keyLength] - 'A'][0] + 26) % 26;
            plaintext += shift + 'A';
            j++;
        }
        else
        {
            plaintext += ciphertext[i];
        }
    }

    return plaintext;
}

int main()
{
    std::string plaintext, key, ciphertext, decryptedtext;

    std::cout << "Enter plaintext: ";
    getline(std::cin, plaintext);

    std::cout << "Enter key: ";
    getline(std::cin, key);

    ciphertext = encryptVigenere(plaintext, key);
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    decryptedtext = decryptVigenere(ciphertext, key);
    std::cout << "Decrypted Text: " << decryptedtext << std::endl;

    return 0;
}