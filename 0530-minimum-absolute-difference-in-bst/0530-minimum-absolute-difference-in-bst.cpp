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
     TreeNode *prev = NULL;
        int minD = INT_MAX;
    void diff(TreeNode *node){
        if(node == NULL) return ;
       
        diff(node->left);

        if(prev != NULL){
           
            minD = min(minD, node->val- prev->val);
        }
        prev = node;

        diff(node->right);
        // return minD;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        // if(root == NULL) return 0;
        diff(root);
        return minD;
    }
};