#include <iostream>
#include <string>

class Solution {
public:
    static int lengthOfLastWord(const std::string &s)
    {
        size_t length = 0;
        bool reached_last_word = false;

        // Skip trailing spaces
        auto crit = s.crbegin();
        auto crend = s.crend();
        for (; crit != crend && *crit == ' '; ++crit);

        // Count the length of the last word
        for (; crit != crend && *crit != ' '; ++crit)
        {
            ++length;
        }

        return length;
    }
};

int main()
{
    std::string input1 = "Hello World";
    std::string input2 = "   fly me   to   the moon  ";
    std::string input3 = "luffy is still joyboy";

    std::cout << Solution::lengthOfLastWord(input1) << std::endl;
    std::cout << Solution::lengthOfLastWord(input2) << std::endl;
    std::cout << Solution::lengthOfLastWord(input3) << std::endl;

    return 0;
}
