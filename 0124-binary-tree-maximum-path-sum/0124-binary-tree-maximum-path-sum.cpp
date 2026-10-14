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
    int sum(TreeNode *root , int& maxS){
        if(root == NULL) return 0;
        
        
    
        int left = max(0 , sum(root->left,maxS));
        int right = max(0 , sum(root->right,maxS));

        int currSum = left + right + root->val;
        
        maxS = max(maxS ,currSum );
        return root->val + max(left , right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxS = INT_MIN;
        sum(root , maxS);
        return maxS;
    }
};