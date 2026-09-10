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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return NULL;

        queue <TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            vector <TreeNode*> levelNodes;
            
            //add the current level nodes
            for(int i = 0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                levelNodes.push_back(curr);

                if(curr->left != NULL){ //as perfect binary tree.
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            
            //Reverse at odd level
            if(level % 2 != 0){//odd
                int left = 0, right = size - 1;
                while(left < right){
                    swap(levelNodes[left]->val, levelNodes[right]->val);
                    left++;
                    right--;
                }
            }

            level++; //increase the level
        }

        return root;
    }
};


/*
1. Level-by-Level Batch Processing:
   - Capturing `int size = q.size()` at the start of each tier isolates individual levels, allowing structural operations to occur across an entire horizontal slice simultaneously.
   
2. Two-Pointer Value Reversal:
   - Instead of structural pointer re-routing, odd levels require mirroring node values. A `vector<TreeNode*>` paired with a standard two-pointer sweep (`left` and `right`) cleanly reverses values from outer edges inward.

Complexity:
- Time: O(N), visiting every node once to traverse and once to swap values.
- Space: O(N) auxiliary space in the worst-case queue storage for the widest tier (bottom leaf level of the binary tree).
*/