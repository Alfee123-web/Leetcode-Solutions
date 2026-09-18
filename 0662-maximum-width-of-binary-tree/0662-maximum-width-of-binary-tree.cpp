/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 1});
        long maxW = 0;

        while (!q.empty()) {
            int level = q.size();
            long left = q.front().second;
            long right = q.back().second;
            maxW = max(maxW, right - left + 1);
            for (int i = 0; i < level; i++) {
                auto [node, index] = q.front();
                q.pop();
            long normalIndex = index - left + 1;
                if (node->left) {
                    q.push({node->left, 2 * normalIndex});
                }
                if (node->right) {
                    q.push({node->right, 2 * normalIndex + 1});
                }
            }
        }
        return maxW;
    }
};