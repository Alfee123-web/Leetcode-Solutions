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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL)
            return NULL;
        if (root->val < low) { // valid
              return trimBST(root->right , low , high);//left subtree
        }
        if (root->val > high) {
            return trimBST(root->left , low , high);//right subtree
        }
        if ( root->val >= low && root->val <= high) {
           root->right =  trimBST(root->right, low, high);
            root->left = trimBST(root->left, low, high);
        }
        return root;
    }
};