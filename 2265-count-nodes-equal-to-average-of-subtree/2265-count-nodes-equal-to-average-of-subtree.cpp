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
   
          pair<int,int>dfs(TreeNode* root,int &ans){
            if(root == NULL) return {0,0};
            pair<int,int>left = dfs(root->left,ans);
            pair<int,int>right = dfs(root->right,ans);
            int totalSum = root->val + left.first + right.first;
            //first = sum , second = count
            int totalCount = 1 + left.second + right.second;
            if(totalSum / totalCount == root->val){
                ans++;
            }
            return {totalSum , totalCount};
        
    }
public:
    int averageOfSubtree(TreeNode* root) {
      int ans =0;
      dfs(root,ans);
      return ans;
    }
};