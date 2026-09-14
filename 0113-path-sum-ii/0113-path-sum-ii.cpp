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
    void isPath(TreeNode* node, int targetSum, vector<int> path,
                vector<vector<int>>& ans) {
        if (node == NULL)
            return;
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL &&
            targetSum == node->val) {
            ans.push_back(path);//copy of vector 
        } else {
            isPath(node->left, targetSum - node->val, path, ans);
            isPath(node->right, targetSum - node->val, path, ans);
        }
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        isPath(root, targetSum, path, ans);
        return ans;
    }
};

