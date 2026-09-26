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
    bool inOrder(TreeNode *root , TreeNode *&prev){
        if(root == NULL) return true;

        if(!inOrder(root->left,prev)) return false;
    
         if(prev && prev->val >= root->val) return false;
         prev = root;

        return inOrder(root->right, prev);
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        return inOrder(root , prev);
       
    }
};
// if(!inOrder(root->left,prev)) return false;
//recursively dives down as far left as possible. If any call down the left branch returns false (meaning a violation was found), it immediately stops and propagates false all the way back up.

