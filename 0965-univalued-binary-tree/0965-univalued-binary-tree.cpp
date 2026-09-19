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
    bool isUni(TreeNode *root , int val){
        
if(root == NULL) return true;

           if(root->val != val) return false;
          return isUni(root->left , val) &&
          isUni(root->right,val);
            
    }
public:
    bool isUnivalTree(TreeNode* root) {
      
       
        return isUni(root,root->val);


    }
};