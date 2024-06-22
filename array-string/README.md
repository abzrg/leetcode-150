# Array/String

## [Merge Sorted Arrays](https://leetcode.com/problems/merge-sorted-array/description/)

## Runtime Complexity

This solution processes each element of `nums1` and `nums2` exactly once, making a total of `m + n` operations, where `m` is the number of initial elements in `nums1` and `n` is the number of elements in `nums2`.

Thus, the runtime complexity is: \( O(m + n) \)

## Space Complexity

The algorithm merges the arrays in-place using the extra space already allocated in `nums1`. It uses a few additional variables (`i`, `j`, `k`) for indices, but these do not depend on the input size.

Thus, the space complexity is:
\( O(1) \)
