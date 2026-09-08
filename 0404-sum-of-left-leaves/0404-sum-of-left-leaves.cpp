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
public:
int sum(TreeNode *p1 , bool isLeft){
    if(!p1) return 0;
    if(isLeft && !p1->left && !p1->right){
        return p1->val;
    }
    return sum(p1->left , true) + sum(p1->right,false);
}
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return sum(root , false);
    }
};