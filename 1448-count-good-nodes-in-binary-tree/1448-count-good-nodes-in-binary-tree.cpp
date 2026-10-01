/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int dfs(TreeNode *root , int max){
        if(root == NULL) return 0;
        int good = 0;
        if(root->val >= max){
            good =1;
            max = root->val;
        }
        good += dfs(root->left , max);
        good += dfs(root->right,max);
        return good;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};