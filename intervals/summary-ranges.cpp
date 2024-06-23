#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    [[nodiscard]] inline static std::vector<std::string> summaryRanges(std::vector<int> &nums)
    {
        std::vector<std::string> result;
        size_t n = nums.size();

        if (n == 0)
        {
            return result;
        }

        // Traverse the array left to right
        for (size_t i = 0; i < n; ++i)
        {
            // Identify the start of the current range
            int start = nums[i];

            // Continue to the next elements while they form a consecutive sequence
            while (i + 1 < n && nums[i + 1] == nums[i] + 1)
            {
                ++i;
            }

            // Identify the end of the current range
            int end = nums[i];

            start == end ? result.emplace_back(std::to_string(start))
                         : result.emplace_back(std::to_string(start) + "->" + std::to_string(end));
        }

        return result;
    }
};

int main()
{
    std::vector<int> nums = {0, 1, 2, 4, 5, 7};
    std::vector<std::string> result = Solution::summaryRanges(nums);

    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i)
    {
        std::cout << '"' << result[i] << '"';
        if (i < result.size() - 1)
        {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
