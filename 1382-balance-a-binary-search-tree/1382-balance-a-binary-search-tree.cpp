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
    void inorder(TreeNode *root , vector<int>&val){
        if(root == NULL) return ;
        inorder(root->left , val);
        val.push_back(root->val);
        inorder(root->right , val);
    }
    TreeNode* buildTree(const vector<int>&val , int l , int r){
        if(l > r) return NULL;
         int m = l + (r-l)/2;
         TreeNode* newNode = new TreeNode(val[m]);

         newNode->left = buildTree(val , l , m-1);
         newNode->right = buildTree(val , m + 1, r);
         return newNode;

     
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>val;
        inorder(root,val);
       
        return buildTree(val , 0 , val.size()-1);
        
    }
};
//BST => FLATTEN => SORTED ARRAY
//INORDER : LEFT => ROOT => RIGHT
