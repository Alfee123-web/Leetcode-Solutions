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
    bool sum(TreeNode *node ,int targetSum){
        if(node == NULL){
            return false;
        }
        if(node->left == NULL && node->right == NULL){
            return targetSum == node->val;
        }
        int rem = targetSum - node->val;
        return sum(node->left,rem) || sum(node->right, rem);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return sum(root , targetSum);//truee
    }
};