#include <iostream>
#include <stack>
#include <unordered_map>

class Solution
{
public:
    [[nodiscard]] inline static bool isValid(const std::string &s)
    {
        std::stack<char> stk;
        std::unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        for (const char &c : s)
        {
            // If c is a closing paren
            if (pairs.find(c) != pairs.end())
            {
                // If the stack is empty or the top doesn't match the expected opening
                if (stk.empty() || stk.top() != pairs[c])
                {
                    return false;
                }
                // Pop the matching opening bracket
                stk.pop();
            }
            else
            {
                // Push the opening bracket
                stk.push(c);
            }
        }

        // Stack should be empty if all brackets are matched
        return stk.empty();
    }
};

int main()
{
    std::string test1 = "()";     // true
    std::string test2 = "()[]{}"; // true
    std::string test3 = "(]";     // false
    std::string test4 = "([)]";   // false
    std::string test5 = "{[]}";   // true

    // To print boolean values as true/false
    std::cout << std::boolalpha;
    std::cout << "Test 1: " << Solution::isValid(test1) << "\n";
    std::cout << "Test 2: " << Solution::isValid(test2) << "\n";
    std::cout << "Test 3: " << Solution::isValid(test3) << "\n";
    std::cout << "Test 4: " << Solution::isValid(test4) << "\n";
    std::cout << "Test 5: " << Solution::isValid(test5) << "\n";

    return 0;
}
