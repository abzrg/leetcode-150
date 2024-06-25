#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>

struct TreeNode
{
    // Assuming the node values are all non-negative
    int m_val{};
    std::unique_ptr<TreeNode> m_left;
    std::unique_ptr<TreeNode> m_right;

    TreeNode() noexcept = default;
    explicit TreeNode(int val) noexcept : m_val(val) {}
    TreeNode(int val, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right)
        : m_val(val), m_left(std::move(left)), m_right(std::move(right))
    {
    }
};

class Solution
{
public:
    [[nodiscard]] static int getMinimumDifference(const TreeNode *root)
    {
        // Starting with maximum possible integer diff
        int min_diff{std::numeric_limits<int>::max()};
        // No previous value
        int prev = -1;

        // Inorder:
        //   1. left subtree traversal
        //   2. Update (if possible) the min_diff and prev
        //   3. right subtree traversal
        // The in-order traversal ensures that nodes are visited in ascending order (for a BST).
        // This makes it straightforward to compute differences between consecutive nodes.
        inOrder(root, prev, min_diff);

        return min_diff;
    }

private:
    // It updates the `prev` value and calculates the difference with the current node's value,
    // updating min_diff whenever a smaller difference is found.
    static void inOrder( // NOLINT
        const TreeNode *node, int &prev, int &min_diff)
    {
        // Leaf node
        if (node == nullptr)
        {
            return;
        }

        // Traverse left subtree
        inOrder(node->m_left.get(), prev, min_diff);

        // Calculate the diff and then update the prev to be the value of current node
        // (If we are not at the root node (where the value of prev is not yet updated))
        if (prev != -1)
        {
            // Calculate the new diff
            min_diff = std::min(min_diff, node->m_val - prev);
        }
        prev = node->m_val;

        // Traverse right subtree
        inOrder(node->m_right.get(), prev, min_diff);
    }
};

int main()
{
    // Create a sample BST
    auto root = std::make_unique<TreeNode>(4);
    root->m_left = std::make_unique<TreeNode>(2);
    root->m_right = std::make_unique<TreeNode>(6);
    root->m_left->m_left = std::make_unique<TreeNode>(1);
    root->m_left->m_right = std::make_unique<TreeNode>(3);

    const int result = Solution::getMinimumDifference(root.get());
    std::cout << "Minimum absolute difference in BST: " << result << '\n';

    return 0;
}
