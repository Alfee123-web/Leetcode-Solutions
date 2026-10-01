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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*>q;
        q.push(root);
       bool foundNULL =false;

        while(!q.empty()){
              TreeNode *curr = q.front();
                q.pop();
              if(curr == NULL){
                foundNULL = true;
              }else{
                // Found a node after a null!
                if(foundNULL) return false;
              

               q.push(curr->left);
               q.push(curr->right);
              }
        }
        return true;
    }
};