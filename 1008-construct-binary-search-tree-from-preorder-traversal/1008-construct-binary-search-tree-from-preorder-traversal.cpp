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
    TreeNode *buildBST(vector<int>& preorder , int& i , int minV , int maxV){
        if(i >= preorder.size()  || preorder[i] < minV || preorder[i] > maxV){
             return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = buildBST(preorder , i , minV , root->val);
        root->right = buildBST(preorder , i , root->val , maxV);
        return root;

    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildBST( preorder , i , INT_MIN , INT_MAX) ;
    }
};