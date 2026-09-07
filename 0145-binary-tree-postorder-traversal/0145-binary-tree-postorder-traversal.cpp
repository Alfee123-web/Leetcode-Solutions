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
void postO(TreeNode* node,vector<int>&ans){
    if(!node) return;
    postO(node->left,ans);
    postO(node->right,ans);
    ans.push_back(node->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postO(root,ans);
        return ans;
    }
};