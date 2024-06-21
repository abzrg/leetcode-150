#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    [[nodiscard]]
    static bool canConstruct(const std::string &ransomNote, const std::string &magazine) // NOLINT
    {
        std::unordered_map<char, int> magazineMap;

        // Count the occurrences of each character in the magazine
        for (const char &c : magazine)
        {
            ++magazineMap[c];
        }

        // Check if the ransom note can be constructed from the magazine characters
        for (const char &c : ransomNote)
        {
            if (magazineMap[c] == 0)
            {
                // Character c is not available or not enough in magazine
                return false;
            }
            // Use one occurrence of character c
            --magazineMap[c];
        }

        return true;
    }
};

int main()
{
    std::string ransomNote1 = "a";
    std::string magazine1 = "b";
    std::string ransomNote2 = "aa";
    std::string magazine2 = "ab";
    std::string ransomNote3 = "aa";
    std::string magazine3 = "aab";

    std::cout << std::boolalpha;
    std::cout << "Test 1: " << Solution::canConstruct(ransomNote1, magazine1) << '\n';
    std::cout << "Test 2: " << Solution::canConstruct(ransomNote2, magazine2) << '\n';
    std::cout << "Test 3: " << Solution::canConstruct(ransomNote3, magazine3) << '\n';

    return 0;
}
