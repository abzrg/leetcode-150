#include <algorithm> // std::max
#include <iostream>
#include <memory>

// Definition for a binary tree node.
struct TreeNode
{
    int m_val{};
    // C++ tip: No need for {}: the default ctor of shared_ptr initializes the pointer to `nullptr`.
    // Thus adding {} after variable would be redundant
    std::shared_ptr<TreeNode> m_left;
    std::shared_ptr<TreeNode> m_right;

    TreeNode() noexcept = default;
    explicit TreeNode(int x) noexcept : m_val(x) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) noexcept // NOLINT
        : m_val(x), m_left(left), m_right(right)
    {
    }
    TreeNode(int x, std::shared_ptr<TreeNode> left,
             std::shared_ptr<TreeNode> right) noexcept // NOLINT
        : m_val(x), m_left(std::move(left)), m_right(std::move(right))
    {
    }
};

class Solution
{
public:
    [[nodiscard]] static inline int maxDepth(const std::shared_ptr<TreeNode> &root) // NOLINT
    {
        // If reached a leaf node (no node)
        if (root == nullptr)
        {
            return 0;
        }

        // Recursively calculate the depth of the left and right subtree
        int leftDepth = maxDepth(root->m_left);
        int rightDepth = maxDepth(root->m_right);

        // Plus one to account for the current node
        return std::max(leftDepth, rightDepth) + 1;
    }
};

int main()
{
    auto root = std::make_shared<TreeNode>(1);
    root->m_left = std::make_shared<TreeNode>(2);
    root->m_right = std::make_shared<TreeNode>(3);
    root->m_left->m_left = std::make_shared<TreeNode>(4);
    root->m_right->m_right = std::make_shared<TreeNode>(5);

    int depth = Solution::maxDepth(root);
    std::cout << "Maximum Depth of Binary Tree: " << depth << std::endl;

    return 0;
}
