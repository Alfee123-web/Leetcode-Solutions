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
    TreeNode *f = NULL;
    TreeNode *s = NULL;
    TreeNode *prev = NULL;
    void inorder(TreeNode *root){
        if(root == NULL) return;

        inorder(root->left);

        if(prev != NULL && root->val < prev->val){
            if(f == NULL){
                f = prev;
            }
            s = root;
        }
        prev = root;

        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        f = NULL;
        s = NULL;
        prev = NULL;
        inorder(root);
        if(f != NULL && s != NULL){
            int t = f->val;
            f->val = s->val;
            s->val = t;
        }
    }
};