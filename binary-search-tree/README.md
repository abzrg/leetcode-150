# Binary Search Tree

## [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/)

Given the `root` of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

```
     4
   /   \
  2     6
 / \
1   3

Input: root = [4,2,6,1,3]
Output: 1
```

### Time complexity

O(n), because we visit each node once.
The `inOrder` function is called recursively for each node, processing each node in constant time (O(1)) within the context of the traversal.

### Space complexity

O(h) where h is the height of the bst. This space is used by call stack during recursion.

- In the worst case, the tree could be skewed (resembling a linked list), making the height equal to the number of nodes (h = n), leading to O(n) space complexity.
- In the best case, for a balanced tree, the height is log(n), leading to O(log n) space complexity.
