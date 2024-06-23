# Hash Map

## [Ransom Note](https://leetcode.com/problems/ransom-note/)

This solution uses an unordered map to count the frequency of characters in the `magazine` string.
It then iterates over the `ransomNote` string to check if each character can be found in the map with the required frequency.

### Runtime Complexity

- Building the frequency map: The algorithm iterates through each character in the `magazine` string, inserting or updating the count of each character in the map. This takes O(m) time, where `m` is the length of the `magazine`.
- Checking the ransom note: The algorithm then iterates through each character in the `ransomNote` string, checking and updating the count in the map. This takes O(n) time, where `n` is the length of the `ransomNote`.

Given that these two operations are sequential, the overall runtime complexity is:
\[ \text{O}(m + n) \]

### Space Complexity

- Map space: The unordered map stores the frequency of characters found in the `magazine`.
  In the worst case, each character in the `magazine` is unique, so the map will have at most `m` entries.
  Thus, the space required by the map is O(m).
  However, according to the problem the characters in the magazine are only lowercase English letters.
  Thus, in practice our hash map will have a limited size and don't grow too much.
  Thus, we can say that the space required for the map is O(1).
- Additional variables: The algorithm uses a few additional variables for iteration and storage, which are O(1).

Therefore, the overall space complexity O(m).
