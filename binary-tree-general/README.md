# Binary Tree General

## [Maximum Depth Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)

Find the maximum depth of a binary tree.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

```
[1, 2, 3, 4, 5, null, null]

    1
   / \
  2   3
 / \
4   5
```

The maximum depth of this binary tree is 3.

### Runtime Complexity

The algorithm visits each node exactly once, leading to a time complexity of O(n).

### Space Complexity

The space complexity is O(h), where h is the height of the binary tree. This space is used by the call stack during the recursion. In the worst case, the height of the tree is n (for a skewed tree), resulting in O(n) space complexity. For a balanced tree, the height is O(\log n).
