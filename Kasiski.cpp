#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm> /// sorting

///
/// @brief Program that uses Kasiski Examination to output a list of probable key lengths
///     of a ciphertext that has been encrypted by the Vigenere cipher method.
///
/// Kasiski examination takes advantage of repeating letters in a Vigenere encrypted text.
/// Longer ciphertexts are easier to examine due to more data to exploit.
/// First we find repeating strings in the plaintext and note the distance between repeats.
/// Next we gather all these distances and factor them. Then we accumulate these factors
/// and observe their counts. We ignore factors of 1 and 2 as they are too short to be feasible.
/// Then we take note of the factors with the highest incidence. These are very likely to be the
/// length of the keyword. For more information see the wikipedia article:
/// https://en.wikipedia.org/wiki/Kasiski_examination
///

///
/// findRepeatedStrings is a function that searches a ciphertext for repeated strings and
/// the distances between those strings. We use a map (a dict) that stores vectors
/// for its flexible size. For our use case, it makes more sense that the int is the key
/// in the key-value pair. We intend to store a bunch of strings associated to a single
/// distance int, hence the map of vectors of strings.
///
std::map<int, std::vector<std::string>> findRepeatedStrings(const std::string &ciphertext)
{
    std::map<int, std::vector<std::string>> distances;

    /// Iterate through the ciphertext
    for (size_t i = 0; i < ciphertext.length(); i++)
    {
        /// Check for repeated strings, starting with minimum length 3
        for (int length = 3; length <= ciphertext.length() - i; ++length)
        {
            std::string substring = ciphertext.substr(i, length); /// take substring
            size_t pos = ciphertext.find(substring, i + length);  /// find next instance

            /// Enter while loop if a repeat is found
            while (pos != std::string::npos)
            {
                /// Calculate the distance between occurrences and push to distances
                int distance = static_cast<int>(pos - i); /// convert size_t to int
                distances[distance].push_back(substring);
                pos = ciphertext.find(substring, pos + length); /// Iterate until pos == npos
            }
        }
    }
    return distances;
}

///
/// findFactors takes an integer and returns a vector of integers that are the factors
/// of the input. This is a simple loop.
///
std::vector<int> findFactors(int n)
{
    std::vector<int> factors;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
        }
    }
    return factors;
}

int main()
{
    std::string ciphertext;

    /// Get ciphertext
    std::cout << "Enter ciphertext: ";
    getline(std::cin, ciphertext);

    std::cout << std::endl;

    ///
    /// Output 1: Compute repeated strings and their distances
    ///
    std::map<int, std::vector<std::string>> distances = findRepeatedStrings(ciphertext);

    std::cout << "Distance: Strings" << std::endl;

    /// Output distance and string pairs
    for (auto &e : distances)
    {
        std::cout << e.first << ": ";
        for (std::string &str : e.second)
        {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    ///
    /// Output 2: Output distance and factors of distances
    ///
    std::cout << "Distance: Factors" << std::endl;

    for (auto &e : distances)
    {
        int distance = e.first;
        std::vector<int> factors = findFactors(distance);

        std::cout << distance << ": ";
        for (int factor : factors)
        {
            std::cout << factor << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    ///
    /// Output 3: Output factors and number of occurences
    ///
    std::cout << "Factor: Occurences" << std::endl;

    /// Key is factors and values are counts
    std::map<int, int> factorCounts;

    for (auto &e : distances)
    {
        int distance = e.first;
        std::vector<int> factors = findFactors(distance);

        /// Accumulate factor counts
        for (int factor : factors)
        {
            factorCounts[factor]++;
        }
    }

    /// Sort factors by their counts in descending order

    ///
    /// sortedFactors is a vector that contains the key-value pairs from factorCounts
    /// std::sort uses a custom function as the 3rd argument, taken from
    /// https://stackoverflow.com/questions/279854/how-do-i-sort-a-vector-of-pairs-based-on-the-second-element-of-the-pair
    ///
    std::vector<std::pair<int, int>> sortedFactors(factorCounts.begin(), factorCounts.end());
    std::sort(sortedFactors.begin(), sortedFactors.end(), [](auto &left, auto &right)
              { return left.second > right.second; });

    /// Write output
    for (const auto &e : sortedFactors)
    {
        std::cout << e.first << ": " << e.second << std::endl;
    }
}