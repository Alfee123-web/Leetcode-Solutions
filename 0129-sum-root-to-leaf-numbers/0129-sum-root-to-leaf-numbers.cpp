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
    int dfs(TreeNode* root, int currS){
        if(root == NULL) return 0;
        currS = currS * 10 + root->val;
        if(root->left == NULL && root->right == NULL){
            return currS;
        }
        return dfs(root->left , currS) + dfs(root->right,currS);
    }
public:
    int sumNumbers(TreeNode* root) { 
     return dfs(root,0);
    }
};
