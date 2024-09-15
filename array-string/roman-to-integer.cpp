#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>

class Solution
{
public:
    static int romanToInt(const std::string &s)
    {
        // Mapping Roman numerals to their respective integer values
        std::unordered_map<char, int> roman_map = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                                   {'C', 100}, {'D', 500}, {'M', 1000}};

        // Convert string to a range of integers using views::transform
        auto values = s | std::views::transform([&roman_map](char c) { return roman_map[c]; });

        int total = 0;

        // Manually handle consecutive values
        auto it = values.begin();
        auto next_it = std::next(it);

        while (next_it != values.end())
        {
            if (*it < *next_it)
            {
                total -= *it;
            }
            else
            {
                total += *it;
            }
            ++it;
            ++next_it;
        }

        // Add the last character's value (since it wasn't included in the loop)
        total += *it;

        return total;
    }
};

int main()
{
    std::string s1 = "III";     // 3
    std::string s2 = "LVIII";   // 58
    std::string s3 = "MCMXCIV"; // 1994
    std::string s4 = "IV";      // 4

    int r1 = Solution::romanToInt(s1);
    int r2 = Solution::romanToInt(s2);
    int r3 = Solution::romanToInt(s3);
    int r4 = Solution::romanToInt(s4);

    std::cout << "The integer value is:" << std::endl;
    std::cout << s1 << ": " << r1 << std::endl;
    std::cout << s2 << ": " << r2 << std::endl;
    std::cout << s3 << ": " << r3 << std::endl;
    std::cout << s4 << ": " << r4 << std::endl;

    return 0;
}
