# Vigenere Encoder and Decoder and Kasiski Examination Program

The Vigenere cipher is a classical cipher that was the standard for encryption until its weaknesses were exposed in the 19th century. Although it is not used anymore, it is a good exercise to write a program to encode, decode, and even exploit its weaknesses.

Encryption involves a plaintext and a key. If the plaintext is longer than the key, then the key is repeated as necessary. Each letter in the key corresponds to a certain amount of shift in the alphabet. For example, if our plaintext were "ATTACKATDAWN", and our key was "LEMON", then the first letter of our plaintext would be shifted by 11 letters since L is the 11th letter (starting with A = 0). This simply results in A become L, since A is the zeroth letter. This process continues, with T shifting by 4 letters, T shifting by 12 letters, and so on.

Decryption is simply the reverse process, using the key to shift in the opposite direction.

For centuries, this was impossible to crack, as one would require knowledge of the key used to encode the data. In the 19th century, a cryptographer named Kasiski discovered a method to decode Vigenere Ciphers. He exploited the fact that the key repeats after a set length. Thus, every n letters, the ciphertext would have the same key applied to it. In large texts, repeating phrases result in strings being repeated in the ciphertext, which can be exploited to reveal the length of the key. When the length of the key is known, the ciphertext can be split into N different substitution ciphers, which can each be decoded using frequency analysis.

I have developed functions that encode, decode, and perform the Kasiski Examination. I do not tackle the frequency analysis to completely decode the ciphertext, as this requires guesswork and a dictionary of commonly used words. These programs demonstrate ability to manipulate Strings (including their char-based nature), arrays, vectors, maps and pairs.

ASSUMPTIONS: Do not enter lowercase letters to encode (messes up the conversion), and for the Kasiski Examination do not enter any whitespace.
