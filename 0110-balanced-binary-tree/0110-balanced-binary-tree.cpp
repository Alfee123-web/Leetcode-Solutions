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
    int dfs(TreeNode *root){
        if(root == NULL) return 0;
         int l = dfs(root->left);
         if(l == -1) return -1;
        int r = dfs(root->right);
        if(r == -1) return -1;
        if(abs(l-r) > 1) return -1;
        return max(l,r) + 1;
        

    }
public:
 
    bool isBalanced(TreeNode* root) {
        //-1,0,1 => height balanced 
      return dfs(root) != -1;
        

    }
};