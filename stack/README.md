# Stack

## [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)

This solution uses a stack to keep track of opening parentheses and a hash map to associate closing parentheses with their corresponding opening counterparts.
It iterates over each character in the input string, performing constant-time operations for each character.

### Runtime Complexity

- Iteration over the string: The algorithm iterates through each character in the string exactly once.
- Map lookups: Checking if a character is a closing parenthesis and finding its corresponding opening parenthesis in the map are constant-time operations, O(1).

Given that all these operations are linear in relation to the length of the string `n`, the overall runtime complexity is:
O(n) where n is the length of the input string.

### Space Complexity

- Stack space: In the worst case, all characters in the string are opening parentheses, which would require the stack to hold all `n` characters. Thus, the space required by the stack is O(n).
- Map space: The unordered map has a fixed size of 3 entries (one for each type of parenthesis), which is O(1).

Considering both the stack and map, the dominant factor is the stack, leading to an overall space complexity of:
O(n)

