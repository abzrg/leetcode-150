#include <iostream>
#include <vector>

class Solution
{
public:
    static inline void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        // Pointer for the end of nums1's valid part
        int i = m - 1;
        // Pointer for the end of nums2
        int j = n - 1;
        // Pointer for the end of nums1's total space
        int k = m + n - 1;

        // Merge in reverse order
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        // If there are any remaining elements in nums2
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }

        // No need to copy the remaining elements of nums1 since they are already in place.
    }
};

int main()
{
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // NOLINT
    int m = 3;
    std::vector<int> nums2 = {2, 5, 6}; // NOLINT
    int n = 3;

    Solution::merge(nums1, m, nums2, n);

    for (int num : nums1)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
