# Array/String

## [Merge Sorted Arrays](https://leetcode.com/problems/merge-sorted-array/description/)

## Runtime Complexity

This solution processes each element of `nums1` and `nums2` exactly once, making a total of `m + n` operations, where `m` is the number of initial elements in `nums1` and `n` is the number of elements in `nums2`.

Thus, the runtime complexity is: O(m + n)

## Space Complexity

The algorithm merges the arrays in-place using the extra space already allocated in `nums1`. It uses a few additional variables (`i`, `j`, `k`) for indices, but these do not depend on the input size.

Thus, the space complexity is:
O(1)


## [Length of Last Word](https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150)

- runtime complexity: O(N)
- space complexity: O(1)

## [Roman to Integer](https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150)

- runtime complexity: O(N)
- space complexity: O(1)

#### Explanation of use of C++-20's `std::view`

```cpp
std::unordered_map<char, int> roman_map = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

auto values = s | std::views::transform([&roman_map](char c) { return roman_map[c]; });
```

This line is using C++20's **ranges** and **views** to create a **transformation view** over the string `s`.

1. **`s`**:
   - `s` is a `std::string` that contains Roman numeral characters (e.g., `"MCMXCIV"`).

2. **`std::views::transform`**:
   - This is a function from the C++20 **ranges** library that creates a **view** over the range (in this case, the string `s`). A **view** is a lazy, non-owning range, meaning it does not store a new collection, but rather provides an interface to work with the original range in a transformed way.
   - `std::views::transform` applies a transformation function to each element of the input range (in this case, each character of the string).

3. **`[&roman_map](char c) { return roman_map[c]; }`**:
   - This is a **lambda function** that captures the `roman_map` by reference (`[&roman_map]`).
   - For each character `c` in the string `s`, this lambda function looks up the corresponding integer value in the `roman_map`. For example, if `c = 'M'`, the lambda returns `1000` because `roman_map['M'] = 1000`.

4. **The Pipe Operator (`|`)**:
   - The `|` operator is used to apply a view transformation to the original range. In this case, it applies `std::views::transform` to the string `s`.

5. **Result (`values`)**:
   - `values` is now a **transformed view** of the string `s`, where each character of `s` has been replaced by its corresponding integer value from the `roman_map`.
   - For example, if `s = "MCMXCIV"`, `values` will contain the integers `[1000, 100, 1000, 10, 100, 1, 5]`.

In summary:

- The code takes the string `s` (containing Roman numerals), applies a transformation to each character using the `roman_map`, and creates a lazy range (`values`) that contains the corresponding integer values.
- This transformation happens **lazily**: no new container is created; instead, when you iterate over `values`, the transformation happens on-the-fly as you access each element.
