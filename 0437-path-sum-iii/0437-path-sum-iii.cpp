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
    int countPath(TreeNode *node , long long targetSum){
        if(node == NULL) return 0;
        int path = 0;
        if(node->val == targetSum){
            path++;
        }  
       path += countPath(node->left,targetSum - node->val);
       path += countPath(node->right,targetSum - node->val);
    return path;

    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        
        return countPath(root, targetSum) + 
        pathSum(root->left , targetSum) +
        pathSum(root->right , targetSum);
        
    }
};
